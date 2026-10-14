class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        array<int, 126> goal = {0};
        array<int, 126> hash = {0};
        int l = 0;
        int minLen = s.size();
        int minR = 0, minL = 0;
        int match = 0;

        for (char c : t) goal[c]++;

        for (int r = 0; r < s.size(); r++) {
            hash[s[r]]++;
            if (hash[s[r]] <= goal[s[r]]) match++;
            while (hash[s[l]] > goal[s[l]]) {
                hash[s[l]]--;
                l++;
            }
            
            if (match == t.size() && (r - l < minLen)) {
                minLen = r - l;
                minR = r;
                minL = l;
            }
        }
        if (match == t.size()) return s.substr(minL, minLen + 1);
        return "";
    }
};