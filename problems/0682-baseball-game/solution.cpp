class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        vector<int> vec;
        for(const auto& str : operations)
            switch(str[0])
            {
                case '+':
                    vec.push_back(*vec.rbegin() + *(++vec.rbegin()));
                    break;
                case 'D':
                    vec.push_back(2 * *vec.rbegin());
                    break;  
                case 'C':
                    vec.pop_back();
                    break;
                default:
                    vec.push_back(stoi(str));
                    break;
            }

        return accumulate(vec.begin(), vec.end(), 0);  
    }
};
