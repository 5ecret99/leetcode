class LRUCache {
private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> lst;
public:
    LRUCache(int capacity)
    :capacity_(capacity){}
    
    int get(int key) 
    {
        auto it = mp.find(key);
        if(it == mp.end())
            return -1; 
        
        auto val = it->second->second;
        put(key, val);
        return val;
    }
    
    void put(int key, int value) 
    {
        auto it = mp.find(key); 
        if(it != mp.end())
        {
            lst.erase(it->second);
        }
        else if(capacity_ == lst.size())
        {
            auto last = lst.back();
            lst.pop_back();
            mp.erase(last.first); 
        }

        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
