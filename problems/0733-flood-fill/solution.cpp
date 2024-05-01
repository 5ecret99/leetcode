class Solution 
{
private:
    int m;
    int n;
    int color_;
    void flood_fill(vector<vector<int>>& image, int x, int y, int scolor)
    {
        if(x < 0 || m <= x
            || y < 0 || n <= y
            || image[x][y] != scolor)
            return;
        
        image[x][y] = color_;
        flood_fill(image, x + 1, y, scolor);
        flood_fill(image, x - 1, y, scolor);
        flood_fill(image, x, y + 1, scolor);
        flood_fill(image, x, y - 1, scolor);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(image[sr][sc] == color) return image;
        m = image.size();
        n = image[0].size();
        color_ = color;
        flood_fill(image, sr, sc, image[sr][sc]);
        return image;
    }
};
