#include<bits/stdc++.h>
using namespace std;

vector <int> sortedArray(vector <int> a, vector <int> b) {
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;          // But No Indexing
    for(int i = 0;i<n1;i++) {
        st.insert(a[i]);
    }
    for(int i = 0; i < n2; i++) {
        st.insert(b[i]);
    }
    vector<int> temp;     // Indexing Is There Now
    for(auto it : st) {
        temp.push_back(it);
    }
    return temp;
}

//-------------------------------------------------------------------------------------


vector<int> sortedArray(vector<int> a, vector<int> b) {
    int n1 = a.size();      // a = [1,2,3,4,5]  n1 = 5
    int n2 = b.size();      // b = [1,6,2,7,8]  n2 = 5
    int i = 0;
    int j = 0;
    vector <int> unionArr;  // unionArr = []

    // Traverse both arrays
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) {    // 1<=1 (True) -> 2<=1 (false)
            if(unionArr.size() == 0 || unionArr.back() != a[i]) {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else {
            if(unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    // If elements are left in array b
    while(j < n2) {
        if(unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    // If elements are left in array a
    while(i < n1) {
        if(unionArr.size() == 0 || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}