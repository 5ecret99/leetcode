class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minheap;
    int k_largest;
public:
    KthLargest(int k, vector<int>& nums) {
        k_largest = k;
        for(const auto& num : nums)
            add(num);
    }
    
    int add(int val) {
        minheap.push(val);
        if(minheap.size() > k_largest)
            minheap.pop();

        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */