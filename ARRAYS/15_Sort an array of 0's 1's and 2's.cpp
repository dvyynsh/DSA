// Input: nums = [1, 0, 2, 1, 0]
// Output: [0, 0, 1, 1, 2]

// We are going to overide the array by counting once how many 0,1,2
// 1.Initialize three counters to count the frequency of 0s, 1s, and 2s
// 2.Loop through the array once and count each number
// 3.In the second loop, fill the array based on the frequency of each number: first 0s, then 1s, then 2s

#include <iostream>
#include <vector>
using namespace std;

void Brute(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;

    // Step 1: Count the occurrences of 0, 1, and 2
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) count0++;
        else if (nums[i] == 1) count1++;
        else count2++;
    }

    // Step 2: Overwrite the array based on the counts
    int index = 0;
    
    for (int i = 0; i < count0; i++) {
        nums[index++] = 0;
    }
    for (int i = 0; i < count1; i++) {
        nums[index++] = 1;
    }
    for (int i = 0; i < count2; i++) {
        nums[index++] = 2;
    }
}

//------------------------------------------------------------------------------------------------------------------
// Dutch National Flag algorithm.
// We divide the array into three partitions using three pointers – low, mid, and high.

// low: Points to the boundary for 0s (everything before low is 0).
// mid: Scans through the array.
// high: Points to the boundary for 2s (everything after high is 2).

// Low,Mid = points starting of the arr
// High = points the last of the arr

void sortColorsOptimal(vector<int>& nums) {
    int low = 0, mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } 
        else if (nums[mid] == 1) {
            mid++;
        } 
        else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
            // Note: mid is not incremented here because the element 
            // swapped from 'high' needs to be evaluated next.
        }
    }
}