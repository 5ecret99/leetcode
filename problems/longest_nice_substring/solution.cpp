class Solution {
public:
    string longestNiceSubstring(string s) {
        int slen=s.size();
        if(slen==1){return "";}
        
        unordered_set<char> st;
        for(auto& ch:s) {st.insert(ch);}
        
        for( int i=0 ; i< slen;i++)
            {
            if(st.find(toupper(s[i]))!=st.end()&&st.find(tolower(s[i]))!=st.end()) continue;
            string s1=longestNiceSubstring(s.substr(0,i));
            string s2=longestNiceSubstring(s.substr(i+1,slen));
            return s1.size()>=s2.size()?s1:s2;
            }
        return s;
    }
};