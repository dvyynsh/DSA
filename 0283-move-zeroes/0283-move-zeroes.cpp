class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0; i< nums.size(); i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }

        // After this loop arr will become
        // nums = [1,3,12,3,12] and j = 3
        // everything before j is correct
        // After j is Garbage

        for(int i = j; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};