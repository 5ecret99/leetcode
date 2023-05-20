class Solution {
public:
    bool isValid(string s) {
        stack<char> check;
        for(auto& ch : s){
            if(ch == '('){
                check.push(')');
            }
            else if(ch == '['){
                check.push(']');
            }
            else if(ch == '{'){
                check.push('}');
            }
            else if(!check.empty() && ch == check.top()){
                check.pop();
            }
            else{
                return false;
            }
        }

        return check.empty();
    }
};
