// n = nums.size()
// ans = 0
// Loop from 1 to n
// Check n % i == 0
// If true, add the square of nums[i-1]
// Return ans
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        // but acc to question the indexing starts from i=1 so we figure out
        for (int i=0; i<n; i++){
            if(n%(i+1)==0){          // becuse in quest it starts from 1
                ans+=nums[i]*nums[i];
            }
        }
        return ans;
    }
};