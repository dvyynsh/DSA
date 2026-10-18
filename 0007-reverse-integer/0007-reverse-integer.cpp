class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int last = x % 10;

            // Check for positive overflow (for passing all testcases)
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && last > 7))
                return 0;

            // Check for negative overflow
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && last < -8))
                return 0;

            ans = ans * 10 + last;
            x /= 10;
        }

        return ans;
    }
};