class Solution {
public:
    int maxArea(vector<int>& height) {
        double sum = 0, i = 0, j = height.size() - 1;
        while(i < j){
            auto temp_sum = j - i;
            if ( height[i] < height[j]){
                temp_sum*= height[i];
                i++;
            }
            else{
                temp_sum*= height[j];
                j--;
            }

            sum = max(temp_sum, sum);
        }

        return (int)sum;
    }
};
