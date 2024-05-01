constexpr size_t HSIZE = 1000;
class MyHashMap 
{
    using Bucket = list<pair<int, int>>;
    using Dict = array<Bucket, HSIZE>;
    Dict dict;
public:
    MyHashMap() {}

    int hash(int key)
    {
        return key % HSIZE;
    }

    Bucket::iterator find(int h, int key)
    {
        auto it = dict[h].begin();
        for(; it != dict[h].end(); ++it)
            if(it->first == key)
            {
                return it;
            }
        
        return dict[h].end(); 
    }

    void put(int key, int value) 
    {
        auto h = hash(key);
        auto it = find(h, key);
        if(it != dict[h].end())
        {
            it->second = value;
            return;
        }
       
        dict[h].emplace_front(key, value);
    }
    
    int get(int key) 
    {
        auto h = hash(key);
        auto it = find(h, key);
        return it == dict[h].end() ? -1 : it->second;
    }
    
    void remove(int key) 
    {
        auto h = hash(key);
        auto it = find(h, key);
        if(it != dict[h].end())
        {
            dict[h].erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

