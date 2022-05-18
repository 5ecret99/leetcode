class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        
        for(int x=0;x<image.size();x++)
            {
            int left=0;
            int right=image[x].size()-1;
            
            while(left<=right)
                {
                if(image[x][left]==image[x][right])
                    {
                    image[x][left]=1-image[x][left];
                    image[x][right]=image[x][left];
                    }
                left++;right--;
                }

            }
    return image;
    }
};
