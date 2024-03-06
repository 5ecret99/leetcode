class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string>  words{wordList.begin(), wordList.end()};
        queue<string> todo;
        todo.push(beginWord);
        words.erase(beginWord);
        int ladder = 1;

        while(!todo.empty())
        {
            int n = todo.size();
            for(int i = 0; i < n; ++i)
            {
                auto word =  todo.front();
                todo.pop();
                for(int j = 0; j < word.size(); ++j)
                {
                    char orig_ch = word[j];
                    if(words.empty()) break;
                    for(char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        word[j] = ch;
                        if(words.contains(word))
                        {
                            todo.push(word);
                            words.erase(word);
                            if(word == endWord)
                                return ladder + 1;
                        }
                    }

                    word[j] = orig_ch;
                }
            }

            ++ladder;
        }
        
        return 0;
    }
};
