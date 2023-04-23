class Solution {
public:
    string intToRoman(int num) {
        vector<int> i_arr = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> r_arr = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        for(auto i = 0; i < i_arr.size(); i++){
            while(num >= i_arr[i]){
                res.append(r_arr[i]);
                num-=i_arr[i];
            }
        }

        return res;
    }
};