class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
       //if (nums.size()<1||nums.size()<=k){return 0}
        sort(nums.begin(),nums.end());
        
        int min_diff=std::numeric_limits<int>::max();
        
        for(int i=0;i+k<=nums.size();i++)
            {
            int temp=abs(nums.at(i)-nums.at(i+k-1));
            if(temp<min_diff) min_diff=temp;

            }
        return min_diff;
    }
};
