class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        // Impossible cases
        // ep: num = 2 and sum = 20 because max sum possible = 9 + 9 = 18
        if (sum < 1 || sum > 9 * num)
            return "";

        string ans = "";

        for (int i = 0; i < num; i++) {

            // Always try the biggest digit first ('9' first)
            int digit = min(9, sum);

            // In 9 _ _ _, remainingBoxes = 4 - 0 - 1 = 3
            int remainingBoxes = num - i - 1;

            // If digit = 9 and sum = 20, remainingSum = 20 - 9 = 11
            int remainingSum = sum - digit;

            // In 3 boxes, maximum possible sum = 3 * 9 = 27
            int maximumPossibleSum = remainingBoxes * 9;

            // Can the remaining boxes hold the remaining sum?
            // If NO, decrease the current digit.
            while (remainingSum > maximumPossibleSum) {
                digit--;

                // Update remaining sum after decreasing the digit
                remainingSum = sum - digit;
            }

            // Convert digit into character and append.
            ans += char('0' + digit);

            // Reduce the remaining sum.
            sum -= digit;
        }

        return ans;
    }
};