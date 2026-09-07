class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& n) {
        sort(n.begin(), n.end());
        unsigned int i = 0;
        vector<vector<int>> rtn;
        while (i < n.size() - 2) {
            if (i > 0 && n[i] == n[i - 1]) {
                i++;
                continue;
            }
            unsigned int j = i + 1;
            unsigned int k = n.size() - 1;
            while (j < k) {
                if (n[i] + n[j] + n[k] > 0)
                    k--;
                else if (n[i] + n[j] + n[k] < 0)
                    j++;
                else {
                    rtn.emplace_back(vector<int>{n[i], n[j], n[k]});
                    j++;
                    k--;
                    while (j < k && n[j] == n[j - 1]) j++;
                    while (j < k && n[k] == n[k + 1]) k--;
                }
            }
            i++;
        }
        return (rtn);
    }
};
