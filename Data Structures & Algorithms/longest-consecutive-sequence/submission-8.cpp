class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> nSet;
        nSet.reserve(nums.size());
        nSet.insert(nums.begin(), nums.end());

        int longest = 0;

        for (int n : nSet) {
            if (!nSet.contains(n - 1)) {
                int currentNum = n;
                int currentStreak = 1;

                while (nSet.contains(currentNum + 1)) {
                    currentNum++;
                    currentStreak++;
                }

                longest = std::max(longest, currentStreak);
            }
        }

        return longest;
    }
};