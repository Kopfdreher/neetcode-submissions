class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> nSet(nums.begin(), nums.end());
        int current = 1;
        int longest = 1;
        for (int n : nSet) {
            if (nSet.contains(n - 1)) continue;
            for (int i = n; nSet.contains(i + 1); i++) {
                current++;
            }
            if (current > longest) longest = current;
            current = 1;
        }
        return longest;
    }
};