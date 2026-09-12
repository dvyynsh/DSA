class Solution {
public:
    // SLIDING WINDOW !
    double findMaxAverage(vector<int>& nums, int k) {

        // Step 1: Calculate the sum of the first window
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Step 2: Store the average of the first window
        double maxAverage = (double)sum / k;

        // Step 3: Slide the window
        for (int i = k; i < nums.size(); i++) {
            sum = sum - nums[i - k] + nums[i];     // sum-nums[0]+nums[4]
            maxAverage = max(maxAverage, (double)sum / k);
        }

        return maxAverage;
    }
};