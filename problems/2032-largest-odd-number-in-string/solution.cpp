class Solution {
public:
    string largestOddNumber(string& num) 
    {
        for(auto it = num.rbegin(); it != num.rend(); ++ it)
            if(*it - '0' & 1)
                return string{num.begin(), it.base()};

        return "";
    }
};
