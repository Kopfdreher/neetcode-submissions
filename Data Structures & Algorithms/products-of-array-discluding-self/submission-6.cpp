auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> prefix(len, 1);
        vector<int> suffix(len, 1);
        vector<int> result(len);

        // Loop 1: Calculate prefix products from left to right
        for (int i = 1; i < len; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Loop 2: Calculate suffix products from right to left and multiply into result
        for (int i = len - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Combine prefix and suffix products
        for (int i = 0; i < len; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};