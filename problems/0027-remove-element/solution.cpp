class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       auto index = 0;
       for(int i = 0; i < nums.size(); i++){
           if(nums[i] != val){
               nums[index++] = nums[i];
           }
       }

       return index;
    }
};
