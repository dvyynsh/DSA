#include <iostream>
#include <vector>
using namespace std;

// Rearrange Array Elements by Sign

// Given an arr of => equal number of Positive and negative numbers
// Rearrange Such that => +ve comes first then -ve then +ve
// Example: Input [3,1,-2,-5,2,-4] => Output [3,-2,1,-5,2,-4]

// Store all positive numbers in one array.
// Store all negative numbers in another array.
// Merge them alternately into the original array.


vector<int> rearrangeArray(vector<int> &nums){
    vector<int> positive;
    vector<int> negative;

    // Store positives and negatives separately
    for (int i = 0; i < nums.size(); i++){
        if (nums[i] > 0)
            positive.push_back(nums[i]);
        else
            negative.push_back(nums[i]);
    }

    // Rearrange alternately
    for (int i = 0; i < positive.size(); i++){
        nums[2 * i] = positive[i];
        nums[2 * i + 1] = negative[i];
    }

    return nums;
}

//----------------------------------------------------------------------------------------------
// But in this Optimal We are not going to use Two arrays

// Declare answer array of size n

// posIndex = 0
// negIndex = 1

// for every element

//     if element is positive

//         ans[posIndex] = element
//         posIndex += 2

//     else

//         ans[negIndex] = element
//         negIndex += 2

// return ans


vector<int> rearrangeArray(vector<int> &nums){
    int n = nums.size();

    vector<int> ans(n);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++){
        if (nums[i] > 0){
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return ans;
}