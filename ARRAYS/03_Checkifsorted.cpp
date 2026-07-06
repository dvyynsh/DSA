#include <iostream>
using namespace std;

int IsSorted(int arr[], int N){
  for (int i=1; i<N; i++){
    if(arr[i] >= arr[i-1]){                 // don't Use if(arr[i+1]>arr[i])   because it raises error If N=5 it exeeds

    }
    else {
      return false;
    }
  } 
  return true;
}