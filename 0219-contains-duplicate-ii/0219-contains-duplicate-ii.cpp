class Solution {
public:
    // k is the Max Allowed distance i.e., thats why last if statement we put
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> set;

        for (int i = 0; i < nums.size(); i++) {

            // Have we seen this number in the current window?
            if (set.count(nums[i])) {       // count=returns 1 if present otherwise false
                return true;
            }

            // Add current number to the Set
            set.insert(nums[i]);

            // Keep only the last k elements in the window
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }

        return false;
    }
};