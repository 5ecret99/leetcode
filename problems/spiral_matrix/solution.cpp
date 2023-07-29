class Solution {
private:
    vector<int> res;
    bool right(vector<vector<int>>& matrix){
        if(matrix.empty() || matrix[0].empty()) return  false;
        for(int i = 0; i < matrix[0].size(); i++)
            res.push_back(matrix[0][i]);

        matrix.erase(matrix.begin());
        return true;
    }
    bool down(vector<vector<int>>& matrix){
        if(matrix.empty() || matrix[0].empty()) return false;
        int n = matrix[0].size() - 1;
        for(int i = 0; i < matrix.size(); i++){
            res.push_back(matrix[i][n]);
            matrix[i].pop_back();
        }

        return true;
    }
    bool left(vector<vector<int>>& matrix){
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size() - 1;
        for(int i = matrix[0].size() - 1; i >= 0; i--)
            res.push_back(matrix[m][i]);

        matrix.pop_back();
        return true;
    }
    bool up(vector<vector<int>>& matrix){
        if(matrix.empty() || matrix[0].empty()) return false;
        for(int i = matrix.size() - 1; i >= 0; i--){
            res.push_back(matrix[i][0]);
            matrix[i].erase(matrix[i].begin());
        }

        return true;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        while(right(matrix) && down(matrix) && left(matrix) && up(matrix));
        return res;
    }
};



