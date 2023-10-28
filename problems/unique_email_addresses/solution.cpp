class Solution {
private:
    string valid_email(const string& email){
        string vemail;
        for(const auto& ch : email){
            switch(ch){
                case '+':
                case '@':
                    break;
                case '.':
                    continue;
                default:
                    vemail+= ch;
                    continue;
            }

            break;
        }

        vemail+= email.substr(email.find('@'));
        return vemail;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(const auto& email : emails)
            st.insert(valid_email(email));
        
        return st.size();
    }
};