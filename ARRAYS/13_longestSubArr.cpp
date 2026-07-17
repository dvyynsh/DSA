// Problem Statement: Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

// input nums = [10, 5, 2, 7, 1, 9], k = 15.  
// returns = "4" as sub arr is [5,2,7,1].

#include <iostream>
using namespace std;

int Brute(int arr[], int N, int K){
    int maxLen = 0;

    for(int i = 0; i < N; i++){
        int sum = 0;

        for(int j = i; j < N; j++){
            sum += arr[j];

            if(sum == K){
                int len = j - i + 1;

                if(len > maxLen){
                    maxLen = len;
                }
            }
        }
    }

    return maxLen;
}

//------------------------------------------------------------------------------------------------------------------
// Prefix Sum = Sum of elements from index 0 to current index
// Index      : 0   1   2   3   4
// Array      : 2   3   5   1   9
// Prefix Sum : 2   5  10  11  20
// so
// Current Prefix Sum = sum
// Suppose we are at index = 4
// Current Prefix Sum = 20
// Previous Prefix Sum = 11, 10, 5, 2
// if K = 10
// Subarray Sum = Current Prefix Sum - Previous Prefix Sum
// 10 = 20 - Previous Prefix Sum
// Previous Prefix Sum = 10 ( Then we cheack is 10 there in map? Yes at (1,3) )


#include <bits/stdc++.h>
int Better(vector<int> a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        preSumMap[sum] = i;
    }
    return maxLen;
}

//------------------------------------------------------------------------------------------------------------------
// Two Pointer Approch
// Like Move if it Exceeds the sum Trim it down


int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left = 0, right = 0;   // Defined two pointers
    long long sum = a[0];      // First number is Itself the sum
    int maxLen = 0;
    int n = a.size();
    while(right < n) {
        while(left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}
