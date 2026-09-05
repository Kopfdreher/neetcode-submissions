class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            while (!isalnum(s[start]) && start < s.size() - 1) start++;
            while (!isalnum(s[end]) && end > 0) end--;

            if (start > end) return true;
            if (toupper(s[start]) != toupper(s[end])) return false;

            start++, end--;
        }

        return true;
    }
};
