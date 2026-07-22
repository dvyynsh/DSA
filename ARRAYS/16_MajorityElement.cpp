#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Input:  nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
// Output: 7  

// 1. Iterate through the array to select each element one by one.
// 2. For each selected element, run another loop to count its occurrences in the given array.
// 3. If count > floor of (N/2), return that element immediately as the majority element.

int majorityElement(vector<int>& nums){
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int count = 0;

        for(int j = 0; j < n; j++){
            if(nums[i] == nums[j]){
                count++;
            }
        }

        if(count > n/2){
            return nums[i];
        }
    }

    // Problem guarantees a majority element exists.
    return -1;
}

//------------------------------------------------------------------------------------------------------------------
// Use: unordered_map<int,int>
// Store: Element → Frequency

int majorityElement(vector<int>& nums){
    unordered_map<int,int> freq;
    int n = nums.size();

    // Count frequency of every element.
    for(int i = 0; i < n; i++){
        freq[nums[i]]++;
    }

    // Find the majority element.
    for(auto it : freq){
        if(it.second > n/2){
            return it.first;
        }
    }

    return -1;
}

//------------------------------------------------------------------------------------------------------------------
// Use: Moore's Voting Algorithm = "Same element gives a vote (+1), different element cancels a vote (-1). The majority element always survives the cancellations"


int majorityElement(vector<int>& nums){
    int candidate = 0;
    int count = 0;

    for(int i = 0; i < nums.size(); i++){
        // If no candidate exists, choose the current element.
        if(count == 0){
            candidate = nums[i];
        }

        // Same candidate gets one more vote.
        if(nums[i] == candidate){
            count++;
        }
        // Different element cancels one vote.
        else{
            count--;
        }
    }

    return candidate;
}
