#include<iostream>
#include<vector>
using namespace std;

vector<int> Brute(int n, vector<int> a) {
    // a = {1,0,2,3,0,4,0,1}
    // temp = {1,2,3,4,1}
    vector<int> temp;
    for(int i = 0; i < n; i++) {
        if(a[i] != 0) {
            temp.push_back(a[i]);
        }
    }

    // nz = 5
    // a = 1 2 3 4 1  4 0 1
    int nz = temp.size();
    for(int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    // i = 5
    for(int i = nz; i < n; i++) {
        a[i] = 0;
    }

    return a;
}


//------------------------------------------------------------------------------------


// Two Pointer Approch (First find that first zero.)
// starting pointer points to "0" and another one adjacent to.

vector<int> moveZeros(int n, vector<int> a) {
    int j = -1;
    // Find the first occurrence of 0
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            j = i;
            break;
        }
    }

    // If no zero exists, return the array as it is
    if(j == -1) return a;

    // Move pointers i and j to swap non-zero elements to the front
    for(int i = j + 1; i < n; i++) {
        if(a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }

    return a;
}

