class Solution {
   public:
    map<pair<int, int>, int> cache = {};
    vector<vector<char>>* m;
    int rows, cols, max_side = 0;
    int maximalSquare(vector<vector<char>>& matrix) {
        rows = matrix.size(), cols = matrix[0].size();
        m = &matrix;

        helper(0, 0);
        return max_side * max_side;
    }

    int helper(int r, int c) {
        if (r >= rows || c >= cols) return 0;
        if (cache.contains({r, c})) return cache[{r, c}];
        int ans = 0;
        int down = helper(r + 1, c);
        int right = helper(r, c + 1);
        int diag = helper(r + 1, c + 1);
        cache[{r, c}] = 0;
        if ((*m)[r][c] == '1') {
            cache[{r, c}] = 1 + min(down, min(right, diag));
        }
        ans = cache[{r, c}];
        max_side = max(max_side, ans);
        return ans;
    }
};