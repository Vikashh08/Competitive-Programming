class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // row size;
        int n = matrix[0].size(); // col size;
        int l = 0, r = (m * n) - 1, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};