static const auto _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
 
class Solution {
public:
    int maxArea(vector<int>& h) {
        int start = 0, end = h.size() - 1, maxA = 0;
        while (start < end) {
            maxA = max(maxA, (end - start) * min(h[start], h[end]));
            if (h[start] < h[end]) start++;
            else end--;
        }
        return maxA;
    }
};
