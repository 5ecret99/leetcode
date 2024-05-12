class BrowserHistory 
{
private:
    using History = list<string>;
    History h_;
    History::iterator curr_;
public:
    BrowserHistory(const string& homepage) 
    {
        h_.push_back(homepage);
        curr_ = --h_.end();
    }
    
    void visit(const string& url) 
    {
        h_.erase(++curr_, h_.end());
        h_.push_back(url); 
        curr_ = --h_.end();
    }
    
    string back(int steps) 
    {
        while(steps-- && curr_ != h_.begin()) curr_--;   
        return *curr_;
    }
    
    string forward(int steps) 
    {
        while(steps-- && curr_ != --h_.end()) curr_++;   
        return *curr_;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
