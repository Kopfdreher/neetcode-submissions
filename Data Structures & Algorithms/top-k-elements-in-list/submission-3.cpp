class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result(k);
        array<int, 2001> freq{};

        for (int num : nums) {
            freq[num + 1000]++;
        }

        for (int i = k; i > 0; i--) {
            int* maxFreq = max_element(freq.begin(), freq.end());
            // calculate the index and shifting it by 1000
            // (freq[0] represents -1000)
            int n = (maxFreq - freq.begin()) - 1000;
            result[i - 1] = n;
            *maxFreq = -1;
        }
        return result;
    }
};
