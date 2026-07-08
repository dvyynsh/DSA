#include <bits/stdc++.h>
using namespace std;

void Brute(int arr[], int n, int d) {
    // Handle cases where d >= n
    d = d % n;
    if (d == 0) return;

    // 1. Store the first d elements in a temporary array
    int temp[d];
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // 2. Shift the remaining elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // 3. Move the elements from the temporary array to the end
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
    // [1, 2, 3, 4, 5]  if d = 2
    // temp [ 1,2 ] and [ 3,4,5 ] and n = 5(given)
    // 3+0 = temp[0]
    // 3+1 = temp[1]
}

//------------------------------------------------------------------------------------



// [1,2,3,4,5,6,7]  d=3 and n=7
// [3,2,1] || [7,6,5,4] reverse whole => [4,5,6,7,1,2,3]
void Optimal(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}


