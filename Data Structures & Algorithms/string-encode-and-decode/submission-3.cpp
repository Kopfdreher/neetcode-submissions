class Solution {
public:

    string encode(vector<string>& strs) {

        // reserving total encoded strlen (str + '#' + num)
        size_t totalCap = 0;
        for (const string& str : strs) {
            totalCap += str.length() + 1 + to_string(str.length()).length();
        }

        string result;
        result.reserve(totalCap);

        for (const string& str : strs) {
            result += to_string(str.length());
            result += "#";
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        size_t end = 0;
        size_t start = 0;
        size_t len = 0;
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
