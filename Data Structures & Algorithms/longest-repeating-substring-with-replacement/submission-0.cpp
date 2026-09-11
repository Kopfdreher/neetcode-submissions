class Solution {
   public:
    int characterReplacement(string s, int k) {
        array<int, 26> hash = {0};
        int l = 0, maxLen = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); r++) {
            hash[s[r] - 'A']++;
            maxFreq = max(hash[s[r] - 'A'], maxFreq);

            while ((r - l + 1) - maxFreq > k) {
                hash[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
