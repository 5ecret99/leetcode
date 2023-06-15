class TrieNode{
    public:
        TrieNode* child[26];
        bool word_end = false;
        TrieNode(){
            for(auto& ch:child)
                ch = nullptr;
        }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto node = root;
        for(auto& ch:word){
            if(!node->child[ch - 'a']) 
                node->child[ch - 'a'] = new TrieNode();
            
            node = node->child[ch - 'a'];
        }

        node->word_end = true;
    }
    
    bool search(string word, bool prefix = false) {
        auto node = root;
        for(auto& ch:word){
            if(!node->child[ch - 'a']) 
                return false;
            
            node = node->child[ch - 'a'];
        }

        return prefix ? true : node->word_end;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */