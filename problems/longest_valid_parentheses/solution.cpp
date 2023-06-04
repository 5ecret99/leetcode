class Solution {
public:
    //int is_valid(string::iterator start, string::iterator end){}

    int longestValidParentheses(string s) {
        stack<string::iterator> opens;
        for(auto it = s.begin(); it != s.end(); it++){
            if(*it == '('){
                opens.push(it);
            }
            else if(opens.size()){
                *opens.top() = *it = '*';
                opens.pop();
            }
        }

        int curr = 0;
        int res = 0;
        for(auto& ch:s){
            if(ch == '*'){
                curr++;
            }
            else{
                res = max(res,curr);
                curr = 0;
            }
        }

        return max(curr, res);
    }
};