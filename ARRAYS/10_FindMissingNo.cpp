// You are given an array of size N-1 containing numbers from 1 to N.
// exactly one number is missing
// N = 5
// arr = {1,2,4,5}
// Output: 3

#include <iostream>
using namespace std;

int Brute(int arr[], int N){
    for (int i = 1; i <= N; i++){
        bool found = false;
        for (int j = 0; j < N - 1; j++){
            if (arr[j] == i){
                found = true;
                break;
            }
        }
        if (found == false){
            return i;
        }
    }

    return -1;
}

//-------------------------------------------------------------------------------------
// Better Approch Uses Hash
// if arr[]={1,2,4,5} and N=5
//  0 1 2 3 4 5 (indices)
//  0 1 1 0 1 1 (initialized was with '0')
// we just neglecting the first zero of hash 
// and thats why we defined hash N+1
int Better(int arr[], int N){
    int hash[N + 1] = {0};

    for(int i = 0; i < N - 1; i++){
        hash[arr[i]] = 1;
    }

    for(int i = 1; i <= N; i++){
        if(hash[i] == 0)
            return i;
    }

    return -1;
}

//-------------------------------------------------------------------------------------
// Optimal 1 (Mathematics)
// If N = 5 && arr = {1,2,4,5}
// We know total exp sum from = {1,2,3,4,5}
// Expected Sum - Actual Sum = missing number
// for N=5 simple use formula sum = 15

int Optimal1(int arr[], int N){
    int expectedSum = N * (N + 1) / 2;
    int actualSum = 0;

    for(int i = 0; i < N - 1; i++){
        actualSum += arr[i];
    }

    return expectedSum - actualSum;
}

//-------------------------------------------------------------------------------------
// Optimal 2 (XOR)
// Same ---> Becomes zero
// If N = 5 && arr = {1,2,4,5}
// (1 2 3 4 5) XOR all of em' --> 1^2^3^4^5
// (1 2 4 5) XOR this also --> 1^2^4^5
// combine them (1 ^ 2 ^ 3 ^ 4 ^ 5) ^ (1 ^ 2 ^ 4 ^ 5)

int Optimal2(int arr[], int N){
    int xor1 = 0;
    int xor2 = 0;

    // XOR all array elements
    for(int i = 0; i < N - 1; i++){
        xor2 ^= arr[i];      
    }

    // XOR all numbers from 1 to n
    for (int i = 1; i <= N; i++) {
        xor1 ^= i;
    }


    return xor1 ^ xor2;
}



