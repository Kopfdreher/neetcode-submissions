class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int mid = 0;
        while (l <= r) {
            mid = l + (r - l) / 2;
            unsigned long hours = 0;
            for (int pile : piles) {
                hours += pile / mid;
                if (pile % mid != 0) hours++;
            }
            if (hours > h) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
