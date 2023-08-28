class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(auto it = digits.rbegin(); it != digits.rend(); ++it){
            if(*it + 1 < 10){
                *it+=1;
                return digits;
            }
            
            *it=0;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};