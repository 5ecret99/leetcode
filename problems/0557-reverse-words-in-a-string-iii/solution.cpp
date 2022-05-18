class Solution {
public:
    string reverseWords(string s) {
        
    for(int i=0;i<s.size();i++)
        {
        
        int j=i;
        while(j<s.size() && s[j]!=' ') j++;
        
        if(s[i]!=' ')
            {
            reverse(s.begin()+i,s.begin()+j);
            i=j-1;
            }
        }
    return s;
    }
};
