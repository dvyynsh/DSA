// Convert the first arr into set to remove duplicacy
// iterate through second arr and check any matching elements
// Then push into ans vector and then remove that element from arr2


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st;
        vector<int> ans;

        // Store all elements of nums1 in the set
        for (int i = 0; i < nums1.size(); i++) {
            st.insert(nums1[i]);
        }

        // Traverse nums2
        for (int i = 0; i < nums2.size(); i++) {
             // Check if element exists in the set
            if (st.find(nums2[i]) != st.end()) {        // means if it's not reaches end of list means element found
                ans.push_back(nums2[i]); 
                st.erase(nums2[i]);   
            }
        }
    return ans;

    }

};
