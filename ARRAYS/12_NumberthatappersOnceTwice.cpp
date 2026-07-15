// Problem Statement
// Arr = {4,1,2,1,2}
// Answer = 4

#include <bits/stdc++.h>
using namespace std;

// Take first element
// Search entire array
// Count how many times it appears
// If count == 1
// Return it

int Brute(int arr[], int N){

    int count = 0;

    for(int i = 0; i < N; i++){

        for(int j = 0; j < N; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(count == 1){
            return arr[i];
        }
    }
    return -1;
}

//-------------------------------------------------------------------------------------

// Instead of counting an element's occurrences again and again, what if we count all elements just once, That leads to the Better Approach (Hashing) with:
// Time: O(N)
// Space: O(N)
// ep: Arr[] = {1,1,2,3,3,4,4}.
// Hash will be defined (Max+1) => 4+1 => 5 as |0|0|0|0|0|.
// If arr has Big data Like 10^12 then we won't use this.
// We can use Unordered map.

int Better1(int arr[], int N){

    int maxi = arr[0];
    
    for(int i = 1; i < N; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }

    int hash[maxi + 1] = {0};

    for(int i = 0; i < N; i++){
        hash[arr[i]]++;
    }

    for(int i = 0; i < N; i++){
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}

#include <unordered_map>

int Better2(int arr[], int N){
    // Example:
    // arr = {4,1,2,1,2}

    unordered_map<int, int> hash;

    // Store the frequency of every element.
    for(int i = 0; i < N; i++){
        hash[arr[i]]++;
    }

    // Find the element whose frequency is 1.
    for(int i = 0; i < N; i++){
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}

//-------------------------------------------------------------------------------------

int Optimal(int arr[], int N){
    // Example:
    // arr = {4,1,2,1,2}

    int xor1 = 0;

    for(int i = 0; i < N; i++){
        xor1 ^= arr[i];
    }

    // 4^1^2^1^2
    // 4^1^1^2^2
    // 4^0^0
    // returns 4 (ans)
    return xor1;
}