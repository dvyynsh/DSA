class Solution {
public:
    // Two Pointer approch
    // "i" reads if found val ignore it otherwise write with "j"
    int removeElement(vector<int>& nums, int val) {
        int k=0;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val){
                //Now first element might also be removed
                nums[j]=nums[i];
                j++;
                k++;
            }
        }
        return k;
    }
};