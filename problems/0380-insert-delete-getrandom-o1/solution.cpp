class RandomizedSet 
{
private:
    unordered_set<int> set_;
public:
    RandomizedSet(){}
    
    bool insert(int val) 
    {
       if(set_.contains(val)) return false;
       set_.insert(val);
       return true; 
    }
    
    bool remove(int val) 
    {
        auto it = set_.find(val);
        if(it == set_.end()) return false;
        set_.erase(it);
        return true;
    }
    
    int getRandom() 
    {
        return *next(set_.begin(), rand() % set_.size());    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
