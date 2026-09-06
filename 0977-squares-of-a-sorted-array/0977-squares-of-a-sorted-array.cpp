class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());    
        int left = 0;
        int right = nums.size()-1;
        int k = nums.size()-1;      // writting pointer
       
        while(left<=right){     // divyansh idea while(k!=-1) also works
            if (abs(nums[left]) > abs(nums[right])) {
                result[k]=nums[left]*nums[left];
                left++;
            }
            else {
                result[k]=nums[right]*nums[right];
                right--;
            }

            k--;
        }
        return result;
    }
    
};