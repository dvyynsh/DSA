#include<iostream>
#include<set>
using namespace std;

int Brute(int arr[], int n)
{
    set<int> st;                 // initialized set = that contains Unique elements

    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);       // n log n
    }

    int index = 0;

    for(auto it : st)            // Just a loop For set
    {
        arr[index] = it;         // storing at that index then incrementing
        index++;                 // log n
    }

    return st.size();        
}

//---------------------------------------------------------------------------------------------------------------------


// using two pointer approch
int Optimal(int arr[], int n)
{
    int i = 0;

    for(int j = 1; j < n; j++)
    {
        if(arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;
}
// time-complexity = only j moves once = O(n)