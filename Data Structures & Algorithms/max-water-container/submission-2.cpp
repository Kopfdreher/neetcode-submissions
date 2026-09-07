class Solution {
public:
    int maxArea(vector<int>& h) {
        int start = 0, end = h.size() - 1, maxA = 0;
        while (start < end) {
            int minH = min(h[start], h[end]);
            maxA = max(maxA, (end - start) * min(h[start], h[end]));

            while (start < end && h[start] <= minH) ++start;
            while (start < end && h[end] <= minH) --end;
        }
        return maxA;
    }
};
