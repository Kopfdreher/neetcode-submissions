class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        array<int, 26> sArr{};
        array<int, 26> tArr{};
        for (char c : s) {
            sArr[c - 'a']++;
        }
        for (char c : t) {
            tArr[c - 'a']++;
        }
        for (size_t i = 0; i < 26; ++i) {
            if (sArr[i] != tArr[i]) return false;
        }
        return true;
    }
};
