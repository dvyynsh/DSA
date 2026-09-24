class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {

            int temp = nums[i];
            int digitSum = 0;

            while (temp > 0) {
                // only three line code
                int last = temp%10;
                digitSum +=last;
                temp /= 10;
            }

            if (digitSum == i)
                return i;
        }
        return -1;
    };
};