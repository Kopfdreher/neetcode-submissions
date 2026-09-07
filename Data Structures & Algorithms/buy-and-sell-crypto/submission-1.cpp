class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int rtn = 0;
        int minP = prices[0];
        for (int p : prices) {
            minP = min(minP, p);
            rtn = max(rtn, p - minP);
        }
        return rtn;
    }
};
