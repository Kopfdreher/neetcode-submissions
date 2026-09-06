#pragma optimize("OFast","unroll-loops");

static const auto fast = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
   public:
    vector<int> twoSum(vector<int>& n, int target) {
        int start = 0;
        int end = n.size() - 1;
        while (start < end) {
            if (n[start] + n[end] < target) start++;
            else if (n[start] + n[end] > target) end--;
            else return vector<int>{start + 1, end + 1};
        }
        return vector<int>{start + 1, end + 1};
    }
};
