class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, bool> c;
        int l = 0, r = 0, maxS = 0;

        while (r < s.size()) {
            while (c[s[r]] == true) c[s[l++]] = false;
            c[s[r]] = true;
            r++;
            maxS = max(maxS, r - l);
        }
        return maxS;
    }
};
