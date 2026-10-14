class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        array<int, 126> goal = {0};
        array<int, 126> hash = {0};
        int l = 0;
        int minLen = s.size();
        int minR = 0, minL = 0;
        bool found = false;

        for (char c : t) goal[c]++;

        for (int r = 0; r < s.size(); r++) {
            hash[s[r]]++;
            while (hash[s[l]] > goal[s[l]]) {
                hash[s[l]]--;
                l++;
            }
            
            if (mapIsFit(goal, hash) && (r - l < minLen)) {
                minLen = r - l;
                minR = r;
                minL = l;
                found = true;
            }
        }
        if (found) return s.substr(minL, minLen + 1);
        return "";
    }

    bool mapIsFit(const array<int, 126> &goal, const array<int, 126> &hash) {
        for (int i = 'A'; i <= 'z'; i++) {
            if (goal[i] > hash[i]) return false;
        }
        return true;
    }
};