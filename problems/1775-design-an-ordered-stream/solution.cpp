class OrderedStream 
{
private:
    vector<string> stream;
    int index = 0;

public:
    OrderedStream(int n) 
    {
        stream.resize(n);    
    }
    
    vector<string> insert(int id, string value) 
    {
        stream[id - 1] = value;
        vector<string> res;
        while(index < stream.size() && !stream[index].empty())
            res.push_back(stream[index++]);
        
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
