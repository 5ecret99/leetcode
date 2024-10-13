class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        auto it1 = word1.begin();
        auto st1 = it1->begin();
        auto it2 = word2.begin();
        auto st2 = it2->begin();

        while(it1 != word1.end() && it2 != word2.end())
        {
            while(st1 != it1->end() && st2 != it2->end())
            {
                if(*st1++ != *st2++)
                {
                    return false;
                }
            }

            if(st1 == it1->end() && ++it1 != word1.end())
            {
                st1 = it1->begin();
            }

            if(st2 == it2->end() && ++it2 != word2.end())
            {
                st2 = it2->begin();
            }
        }

        return it1 == word1.end() && it2 == word2.end();
    }
};
