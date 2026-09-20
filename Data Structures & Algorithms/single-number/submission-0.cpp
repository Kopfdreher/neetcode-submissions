class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> nSet;

        for (auto n : nums) {
            if (nSet.contains(n)) nSet.erase(n);
            else nSet.insert(n);
        }
        return *nSet.begin();
    }
};
