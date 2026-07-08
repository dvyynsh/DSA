// So you need to left rotate an arrays by one places
// [1,2,3,4,5] => [2,3,4,5,1]
// Pretty Easy Problem so Directly Jump to the OPTIMAL

#include <bits/stdc++.h>
using namespace std;

vector<int> Optimal(vector<int> &arr, int n){
    int temp = arr[0];          // stored first element
    for(int i=0; i<n; i++){
        arr[i-1] = arr[i];      // shifting left
    }
    arr[n-1] = temp;
    return arr;
}