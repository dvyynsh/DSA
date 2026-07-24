#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array representing a permutation of numbers
// find the next lexicographically greater permutation.
// If no next permutation exists,
// return the smallest permutation (sorted in ascending order).

// Example: for [1 2 3] arr total permuatations are 
// 123
// 132
// 213
// 231
// 312
// 321

// so we need to return after ( 123 -> 132 ) like wise

// Step 1: Generate all possible permutations.
// Step 2: Sort all the permutations in lexicographical order.
// Step 3: Find the current permutation (132). and return it.


vector<int> nextPermutation(vector<int> nums){  
    // nums = [1,3,2]

    vector<int> original = nums;   // save orignal arr
    vector<vector<int>> permutations;

    // Generate all permutations
    sort(nums.begin(), nums.end());
    // nums = [1,2,3]

    do{
        permutations.push_back(nums);
    }
    while (next_permutation(nums.begin(), nums.end()));  
    // next_permutation is a function it will generate [1,2,3], [1,3,2] , [2,1,3] ,etc

    // Find the current permutation
    for (int i = 0; i < permutations.size(); i++){
        if (permutations[i] == original){  // [1,2,3] == [1,3,2] false [1,3,2] == [1,3,2] true
            // If the current permutation is the last one, return the first permutation.
            if (i == permutations.size() - 1)
                return permutations[0];
            else
                return permutations[i + 1];  // returns permutations[1+1] -> [213] 
        }
    }

    return {};
}

//---------------------------------------------------------------------------------------------------------------
// Find the pivot → Swap with the next larger element on the right → Reverse the suffix.


void nextPermutation(vector<int>& nums){
    int n = nums.size();

    // Step 1: Find the pivot
    int pivot = -1;

    for (int i = n - 2; i >= 0; i--){
        if (nums[i] < nums[i + 1]){
            pivot = i;
            break;
        }
    }

    // If no pivot exists, array is the last permutation
    if (pivot == -1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 2: Find the next larger element from the right
    for (int i = n - 1; i > pivot; i--){
        if (nums[i] > nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }

    // Step 3: Reverse the suffix
    reverse(nums.begin() + pivot + 1, nums.end());
}

