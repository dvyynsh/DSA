class Solution {
public:
    // Function to calculate the sum of digits
    int digitSum(int x) {
        int sum = 0;

        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {

        // Step 1: Create the target sorted array
        vector<int> target = nums;

        // Sort according to digit sum // (learn about this sorting)
        sort(target.begin(), target.end(), [&](int a, int b) {
            int sumA = digitSum(a);
            int sumB = digitSum(b);
        
            if (sumA != sumB)
                return sumA < sumB;

            return a < b;
        });

        // Step 2: Store current positions of every element
        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        // Step 3: Convert nums into target
        for (int i = 0; i < nums.size(); i++){
            // Already correct
            if (nums[i] == target[i])
                continue;

            // Find where the correct element is
            int correctIndex = pos[target[i]];

            // Update map before swapping
            pos[nums[i]] = correctIndex;
            pos[target[i]] = i;

            // Swap
            swap(nums[i], nums[correctIndex]);

            swaps++;
        }
        return swaps;
    }
};       