class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (const string& str : strs) {
            int strLen = str.size();
            result += format("{}#{}", strLen, str);
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        string lenStr = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                lenStr += s[i];
            } else if (s[i] == '#') {
                int lenInt = stoi(lenStr);
                lenStr = "";
                result.emplace_back(s.substr(i + 1, lenInt));
                i += lenInt;
            }
        }

        return result;
    }
};
