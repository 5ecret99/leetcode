class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto& prefix = strs[0];
        for(auto str : strs){
            if(prefix.size() > str.size()){
                prefix = prefix.substr(0, str.size());
            }
            
            for(int i =0 ; i < prefix.size() ; i++){
                if( prefix[i] != str[i]){
                    prefix = prefix.substr(0, i); 
                    break;
                }
            }

            if (prefix.empty()){
                return "";
            }
        }

        return prefix;
    }
};
