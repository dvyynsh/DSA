#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Same problem statement but here we add three more variables
// Keep extending the current subarray. If (sum < 0), discard it and start a new subarray. Whenever you find a better sum, remember its start and end indices.

// 1.Initialize:
//     sum = 0
//     maxi = INT_MIN
//     start = 0
//     ansStart = ansEnd = -1

// 2.Traverse the array:

// 3.Continue Add the current element to sum:

// 4.If sum > maxi:
//     Update maxi.
//     Store start as ansStart and current index as ansEnd.

// 5.If sum < 0:
//     Reset sum = 0.  
//     Set start = i + 1 (new subarray starts here).

// 6.After traversal, print elements from ansStart to ansEnd.

vector<int> maxSubArray(vector<int> &nums){
    int sum = 0;
    int maxi = INT_MIN;

    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;

    for (int i = 0; i < nums.size(); i++){
        sum += nums[i];

        if (sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0){
            sum = 0;
            start = i + 1;
        }
    }

    vector<int> ans;

    for (int i = ansStart; i <= ansEnd; i++){
        ans.push_back(nums[i]);
    }

    return ans;
}

