class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int,int>> products(len);
        vector<int> result(len);

        products[0].first = 1;
        products[len - 1].second = 1;

        for (int i = 1; i < len; i++) {
            products[i].first = nums[i - 1] * products[i - 1].first;
            products[len - i - 1].second = nums[len - i] * products[len - i].second;
        }

        for (int i = 0; i < len; i++) {
            result[i] = products[i].first * products[i].second;
        }
        return result;
    }
};
