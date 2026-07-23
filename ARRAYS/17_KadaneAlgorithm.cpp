#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Problem Statement
// Given an integer array, find the contiguous subarray with the maximum sum.
// Contiguous means the elements must be adjacent.

// Example: nums = {-2,1,-3,4,-1,2,1,-5,4}
// Maximum Subarray: {4  -1  2  1} Returns = 6

// 1️⃣ Brute Force
// Generate every possible subarray.
// Calculate every subarray sum.
// Take maximum

int maxSubArray(vector<int>& nums){
    int n = nums.size();

    // Stores the maximum subarray sum.
    int maxi = INT_MIN;

    // Pick the starting index.
    for(int i = 0; i < n; i++){
        // Pick the ending index.
        for(int j = i; j < n; j++){
            int sum = 0;

            // Calculate the sum of subarray from [i...j].
            for(int k = i; k <= j; k++){
                sum += nums[k];
            }

            // Update the maximum sum.
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
//------------------------------------------------------------------------------------------------------------------
// 2️⃣ Better
// Generate every subarray.
// Maintain running sum instead of recalculating.

int maxSubArray(vector<int>& nums){
    int n = nums.size();

    // Stores the maximum subarray sum.
    int maxi = INT_MIN;

    // Pick the starting index.
    for(int i = 0; i < n; i++){
        int sum = 0;   // Running sum for subarrays starting at i.

        // Extend the subarray one element at a time.
        for(int j = i; j < n; j++){
            // Add the new element.
            sum += nums[j];

            // Update the maximum sum.
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//------------------------------------------------------------------------------------------------------------------
// 3️⃣ Optimal
// Kadane's Algorithm

// A negative running sum only hurts future subarrays.
// So whenever our running sum becomes negative, discard it and start a new subarray from the next element.
// This single idea is Kadane's Algorithm.

// sum = 0
// maxi = -∞

// Traverse the array

//     sum += nums[i]

//     Update maximum

//     If(sum < 0)
//         sum = 0


int maxSubArray(vector<int>& nums){
    int sum = 0;
    int maxi = INT_MIN;

    for(int i = 0; i < nums.size(); i++){
        // Add the current element to the running sum.
        sum += nums[i];

        // Update the maximum subarray sum found so far.
        maxi = max(maxi, sum);

        // If the running sum becomes negative,
        // discard it because it can't help future subarrays.
        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}