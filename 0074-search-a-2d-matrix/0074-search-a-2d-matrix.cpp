class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if (r == 0) return false;
        
        int c = matrix[0].size();
        int r1 = 0, r2 = r - 1, mid; // Declare r2 separately
        while (r1 < r2) {
            mid = r1 + (r2 - r1) / 2;
            if (matrix[mid][c - 1] < target)
                r1 = mid + 1;
            else if (matrix[mid][0] > target)
                r2 = mid - 1;
            else {
                r1 = mid;
                break;
            }
        }
        
        int c1 = 0, c2 = c - 1;
        while (c1 <= c2) {
            mid = c1 + (c2 - c1) / 2;
            if (matrix[r1][mid] < target)
                c1 = mid + 1;
            else if (matrix[r1][mid] > target)
                c2 = mid - 1;
            else
                return true;
        }
        return false;
    }
};
