class TrieNode{
    public:
        TrieNode* childs[26];
        bool word_end = false;
        TrieNode(){
            for(auto& ch:childs)
                ch = nullptr;
        }
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
    
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> childs[word[i] - 'a'];
            } 
            else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> childs[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node->word_end;
    }
    public:
    WordDictionary() {}
    
    void addWord(string word) {
        auto node = root;
        for(auto& ch:word){
            if(!node->childs[ch - 'a']) 
                node->childs[ch - 'a'] = new TrieNode();
            
            node = node->childs[ch - 'a'];
        }
    
        node->word_end = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */