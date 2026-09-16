class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int left = 0, right = matrix.size() * matrix[0].size() - 1, mid = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        while (left <= right) {
            mid = left + ((right - left) / 2);
            if (matrix[mid / cols][mid % cols] == target)
                return true;
            else if (matrix[mid / cols][mid % cols] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
