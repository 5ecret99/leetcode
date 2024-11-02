class MagicDictionary 
{
private:
    unordered_map<int, unordered_set<string>> mp;
public:
    MagicDictionary(){}
    
    void buildDict(const vector<string>& dict) 
    {
        for(auto& word : dict)
            mp[word.size()].insert(word);
    }
    
    bool search(const string& sword) 
    {
        for(auto& word : mp[sword.size()])
        {
            int count = 0;
            for(int i = 0; i < word.size(); ++i)
                if(word[i] != sword[i] && ++count > 1)
                    break;
            
            if(count == 1)
                return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
