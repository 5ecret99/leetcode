class Solution {
public:
    string helper(int n, string s = "1"){
        if(n <= 1) return s;
        stringstream stream;
        auto prev = s[0];
        auto count = 1;
        for(int i = 1; i < s.size(); i++){        
            if(s[i] == prev){
                count++;
            }
            else{
                stream << count << prev;
                prev = s[i];
                count = 1;
            }
        }

        stream << count << prev;
        return helper(--n, stream.str());
    }    
    string countAndSay(int n) {
        return helper(n);
    }
};