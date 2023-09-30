class Solution {
private:
    vector<vector<int>> pascal = {{1}};
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return pascal;

        vector<int> row = {1};
        for(auto it = pascal.rbegin()->begin() + 1; it != pascal.rbegin()->end(); ++it)
            row.push_back(*it + *(it - 1));
        
        row.push_back(1);
        pascal.push_back(row);

        return generate(--numRows); 
    }
};
