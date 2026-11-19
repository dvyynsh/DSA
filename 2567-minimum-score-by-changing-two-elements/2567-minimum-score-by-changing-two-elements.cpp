class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // reminder -> we actually didn't changed it we just ignored it
        // these cases only for high as low always be 0
        int case1 = nums[n-1] - nums[2]; //change first two 
        int case2 = nums[n-3] - nums[0]; // change last and second last
        int case3 = nums[n-2] - nums[1]; // change first & last

        return min({case1, case2, case3});
    }
};