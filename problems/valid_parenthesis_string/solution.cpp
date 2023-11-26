class Solution {
public:
    bool checkValidString(const string& s) {
        stack<int> stars;
        stack<int> parenthesis;
        for(int i = 0; i < s.size(); ++i){
            switch(s[i]){
                case '(':
                    parenthesis.push(i);
                    break;
                case '*':
                    stars.push(i);
                    break;   
                default:
                    if(!parenthesis.empty()) parenthesis.pop();
                    else if(!stars.empty()) stars.pop();
                    else return false;
                    break;
            }
        }

        while(!parenthesis.empty() && !stars.empty()){
            if(parenthesis.top() > stars.top()) return false;

            stars.pop();
            parenthesis.pop();
        }
        
        return parenthesis.empty();
    }
};