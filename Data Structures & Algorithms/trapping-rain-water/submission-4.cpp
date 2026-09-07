static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size() - 1;
        int lMax = h[l], rMax = h[r];
        int res = 0;

        while (l < r) {
            if (lMax < rMax) {
                ++l;
                lMax = max(lMax, h[l]);
                res += lMax - h[l];
            } else {
                --r;
                rMax = max(rMax, h[r]);
                res += rMax - h[r];
            }
        }
        return res;
    }
};
