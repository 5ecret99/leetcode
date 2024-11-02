class MyHashSet 
{
private:
    bitset<1000001> checker;
public:
    void add(int key) 
    {
        checker.set(key);
    }
    
    void remove(int key) 
    {
        checker.set(key, false);
    }
    
    bool contains(int key) 
    {
        return checker.test(key);    
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
