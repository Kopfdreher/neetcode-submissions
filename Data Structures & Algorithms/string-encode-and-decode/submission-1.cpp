class Solution {
public:

    string encode(vector<string>& strs) {
        string result;

        for (const string& str : strs) {
            result += to_string(str.length());
            result += "#";
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        int end = 0;
        int start = 0;
        int len = 0;
        vector<string> result;
        while (1) {
            end = s.find('#', start);
            if (end == string::npos) break;
            len = stoi(s.substr(start, end - start));
            result.push_back(s.substr(end + 1, len));
            start = end + 1 + len;
        }
        return result;
    }
};
