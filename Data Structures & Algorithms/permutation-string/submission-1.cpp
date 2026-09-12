class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size() || s1.empty() || s2.empty()) return false;

        array<int, 26> hash = {};
        array<int, 26> curr = {};
        int l = 0;

        for (char c : s1) hash[c - 'a']++;

        curr = hash;
        for (int r = 0; r < s2.size(); r++) {
            if (curr[s2[r] - 'a'] > 0) curr[s2[r] - 'a']--;
            else if (hash[s2[r] - 'a'] == 0) {
                curr = hash;
                l = r + 1;
            } else {
                while (s2[l] != s2[r]) {
                    curr[s2[l] - 'a']++;
                    l++;
                }
                curr[s2[r] - 'a']--;
            }
            if (foundPermutation(curr)) return true;
        }
        return false;
    }

    bool foundPermutation(array<int, 26> curr) {
        for (int i : curr)
            if (i > 0) return false;
        return true;
    }
};
