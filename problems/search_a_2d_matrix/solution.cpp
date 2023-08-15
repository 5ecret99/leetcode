class Solution {
private:
    int searchMatrix(vector<vector<int>>& matrix, int target, int start, int end){
        if(start > end) return -1;
        int mid = start + (end - start) / 2;
        int mid_value = matrix[mid / matrix[0].size()][mid % matrix[0].size()];
        if(target == mid_value) return mid;

        return target < mid_value ? searchMatrix(matrix, target, start, mid - 1)
            : searchMatrix(matrix, target, mid + 1, end);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, target, 0, matrix.size() * matrix[0].size() - 1) != -1;
    }
};