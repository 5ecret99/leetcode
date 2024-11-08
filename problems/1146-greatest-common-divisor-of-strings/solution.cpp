class Solution 
{
private:
    bool check(string_view str, string_view div)
    {
        for(int i = 0; i < str.size(); ++i)
            if(str[i] != div[i % div.size()])
                return false;
        
        return true;
    }
public:
    string gcdOfStrings(string_view str1, string_view str2) 
    {
        string_view div{str1.substr(0, gcd(str1.size(), str2.size()))};
        return  check(str1, div) && check(str2, div) ? string(div) : "";    
    }
};
