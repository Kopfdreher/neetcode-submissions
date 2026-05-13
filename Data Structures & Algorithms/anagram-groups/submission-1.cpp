class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string, vector<string>> anagram;

       for (const string& str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagram[sortedStr].push_back(str);
       } 

       vector<vector<string>> result;
       for (auto& pair : anagram) {
        result.push_back(move(pair.second));
       }

       return result;
    }
};
