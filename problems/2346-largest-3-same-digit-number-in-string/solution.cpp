class Solution {
public:
    string largestGoodInteger(string& num) 
    {
        char good = '0' - 1;
        for(int i = 2; i < num.size(); ++i)
            if(num[i] == num[i - 1] && num[i] == num[i - 2] && num[i] > good)
                good = num[i];
        
        return good == '/' ? "" : string(3, good);
    }
}; 
