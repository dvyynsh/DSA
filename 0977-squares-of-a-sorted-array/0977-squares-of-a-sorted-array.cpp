class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result;
        for(int i=0; i<nums.size(); i++){
            // result[i]=nums[i]*nums[i];  raise an error because 
            // there is no element in vector result do instead pushback
            result.push_back(nums[i]*nums[i]);
        }
        sort(result.begin(),result.end());
        return result;  
    } 
    
};