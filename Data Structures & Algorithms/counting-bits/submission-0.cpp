class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits;
        for (int i = 0; i <= n; i++) {
            int single = 1;
            bits.push_back(0);
            for (int j = 0; j < 32; j++) {
                if (single & i) bits.back()++;
                single = single << 1;
            }
        }
        return bits;
    }
};
