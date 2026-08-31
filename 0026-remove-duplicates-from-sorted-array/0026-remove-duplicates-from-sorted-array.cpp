class Solution {
public:
    // Remember, the problem says modify the array.
    // i=reader and j=writer
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        for (int i=0; i<nums.size(); i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};