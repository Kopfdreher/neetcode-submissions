auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int>> products(len, {1, 1});
        vector<int> result(len);

        for (int i = 1; i < len; i++) {
            products[i].first = products[i - 1].first * nums[i - 1];
        }

        for (int i = len - 2; i >= 0; i--) {
            products[i].second = products[i + 1].second * nums[i + 1];
        }

        for (int i = 0; i < len; i++) {
            result[i] = products[i].first * products[i].second;
        }

        return result;
    }
};