class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int n : nums) {
            // If n is already in the set, we found a duplicate
            if (seen.find(n) != seen.end()) {
                return true;
            }
            // Otherwise, add it to the set and keep looking
            seen.insert(n);
        }

        return false;
    }
};