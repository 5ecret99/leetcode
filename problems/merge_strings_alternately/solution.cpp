class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        while(true){
            if(it1 == word1.end()){
                res+= word2.substr(distance(word2.begin(), it2));
                break;
            }
            else if(it2 == word2.end()){
                res+= word1.substr(distance(word1.begin(), it1));
                break;
            }

            res += *it1++;
            res += *it2++;
        }

        return res;
    }
};