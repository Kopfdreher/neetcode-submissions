class Solution {
   public:
    int hammingWeight(uint32_t n) {
        uint32_t one = 1;
        uint32_t bits = 0;
        for (int i = 0; i < 32; i++) {
            if (n & one) bits++;
            one = one << 1;
        }
        return bits;
    }
};
