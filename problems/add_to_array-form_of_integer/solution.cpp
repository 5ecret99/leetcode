class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        for(auto it = num.rbegin(); it != num.rend(); ++it){
            *it+= k;
            k = *it/10;
            *it%= 10;
        }

        vector<int> remaining;
        while(k){
            remaining.push_back(k % 10);
            k/= 10;
        }

        num.insert(num.begin(), remaining.rbegin(), remaining.rend());
        return num;
    }
};