class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<pair<int, int>> pairs;
        vector<int> result;

        for (int num : nums) {
            counts[num]++;
        }

        for (const auto& [num, freq] : counts) {
            pairs.push_back({freq, num});
        }

        sort(pairs.rbegin(), pairs.rend());

        for (int i = 0; i < k; i++) {
            result.push_back(pairs[i].second);
        }

        return result;
    }
};
