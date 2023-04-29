class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> keys{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations{""};
        for(auto& digit : digits){
            vector<string> temp{};
            for(auto ch : keys[digit - '2']){
                for(auto& combo : combinations){
                    temp.push_back(combo + ch);
                }
            }
            combinations = temp;
        }

        return combinations;
    }
};