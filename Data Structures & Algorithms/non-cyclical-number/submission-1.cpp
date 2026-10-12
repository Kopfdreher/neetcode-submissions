class Solution {
public:
    bool isHappy(int n) {
        set<int> sums;
        while (1) {
            int sum = squareDigits(n);
            if (sum == 1) break;
            if (sums.contains(sum)) return false;
            else sums.insert(sum);
            n = sum;
        }
        return true;
    }

    int squareDigits(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};
