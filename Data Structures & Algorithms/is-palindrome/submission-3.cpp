class Solution {
public:
    bool isPalindrome(string s) {
        string r(s.rbegin(), s.rend());
        int i = 0;
        int j = 0;

        while (i < s.size() && j < s.size()) {
            // Check bounds while skipping non-alphanumeric characters
            while (i < s.size() && !isalnum(s[i])) {
                i++;
            }
            while (j < s.size() && !isalnum(r[j])) {
                j++;
            }

            // Stop if either index reaches the end
            if (i >= s.size() || j >= s.size()) break;

            if (tolower(s[i]) != tolower(r[j])) return false;

            i++;
            j++;
        }

        return true;
    }
};