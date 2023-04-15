class Solution {
public:
    string longest_pal(string& s, string::iterator it, string::iterator nit){
        while(it != s.begin() -1 && nit !=s.end() && *it == *nit){
            --it;
            ++nit;
        }

        return string(it + 1, nit);
    }

    string longestPalindrome(string s) {
        string answer;
        for (auto it = s.begin(); it != s.end(); it++) {
            auto odd = longest_pal(s, it -1 , it + 1);  
            if(odd.size() > answer.size()){
            answer = odd;
            }            

            auto even = longest_pal(s, it, it + 1);
            if(even.size() > answer.size()){
            answer = even;
            }    
        }

        return answer;
    }
};
