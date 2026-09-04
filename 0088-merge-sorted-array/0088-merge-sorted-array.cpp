// Reverse Two Pointer
// Two arr already sorted in their seperate
// we will follow like in arr1=[1,2,3] and arr2=[2,5,6]
// compare last element 6>3 put 6 at the end of arr1 similarly 5 > 3
// the guy who wins that moves(I mean that pointer moves)
// And "k" always move (means k--)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;   // pionting to "3" of nums1
        int j = n-1;   // pointing to "6" of nums2
        int k = m+n-1; // pointing to "last element of nums1"

        // for loop can't do this as three pointers are there
        while(i >= 0 && j >= 0){

            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }
            else{
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};