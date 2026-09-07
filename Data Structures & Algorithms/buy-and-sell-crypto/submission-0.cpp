class Solution {
public:
    int maxProfit(vector<int>& p) {
        int rtn = 0;
        int minP = p[0];
        for (int i = 0; i < p.size(); i++) {
            minP = min(minP, p[i]);
            rtn = max(rtn, p[i] - minP);
        }
        return rtn;
    }
};
