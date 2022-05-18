class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        for(int i=0;i<words.size();i++)
            {
            int left=0;
            int right=words[i].size()-1;
            int flag=0;
            while(left<=right)
                {

                if(words[i][left]!=words[i][right])
                    {
                    flag=1;break;
                    }
                left++;right--;
                }
            if(flag==0)return words[i];
            }
        return "";
        
    }
};