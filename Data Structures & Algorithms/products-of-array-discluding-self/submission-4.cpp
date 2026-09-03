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

        // First loop: Calculate all prefix and suffix products
        for (int i = 1; i < len; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            suffix[len - i - 1] = suffix[len - i] * nums[len - i];
        }

        // Second loop: Combine prefix and suffix products into the final result
        for (int i = 0; i < len; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};