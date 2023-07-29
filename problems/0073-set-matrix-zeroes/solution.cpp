class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row; 
        unordered_set<int> column;
        for(int i = 0; i < matrix.size(); i++) 
            for(int j = 0; j < matrix[0].size(); j++) 
                if(!matrix[i][j]){
                    row.insert(i);
                    column.insert(j);
                }
        
        for(int i = 0; i < matrix.size(); i++) 
            for(int j = 0; j < matrix[0].size(); j++) 
                if(row.find(i) != row.end() || column.find(j) != column.end())
                    matrix[i][j] = 0;
    }
};
