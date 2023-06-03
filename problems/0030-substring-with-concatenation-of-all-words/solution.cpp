class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        auto word_size = words[0].size();
        vector<int> res;
        unordered_multiset<string> words_set;
        for(auto& word : words){
            words_set.insert(word);
        }

        for(int i = 0; i + word_size * words.size() <= s.size(); i++){
            auto pos = i;
            auto set = words_set;
            while(true){
                auto it = set.find(s.substr(pos,word_size));
                if(it != set.end()){
                    set.erase(it);
                    pos+= word_size;
                }
                else{
                    break;
                }
            }
            
            if (set.empty()){
                res.push_back(i);
            }
        }

        return res;
    }
};
