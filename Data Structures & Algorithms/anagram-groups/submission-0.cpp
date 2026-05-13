class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> bucket;
        vector<vector<string>> result;

        for (string& str : strs) {

            array<int, 26> count{};
            for (char c : str) {
                count[c - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; ++i) {
                key += "#" + to_string(count[i]);
            }

            if (bucket.find(key) != bucket.end()) {
                result[bucket[key]].push_back(str);
            } else {
                bucket[key] = result.size();
                result.push_back({str});
            }
        }
        return result;
    }
};
