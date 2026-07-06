#include <iostream>
using namespace std;

// Arr --> Traversal --> Loop
int LargestElement(int arr[], int N){
  int max = arr[0];
  for (int i=0; i<N; i++){       // start from i=1 for minor performance improvement
    if(arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}
// TimeComplexity = O(N)
// spaceComplexity = O(1)


int main(){
  int a[5] = {1,2,3,4,5};
  int N = 5;

  cout << LargestElement(a, N);     
  // if No "cout" then No result on screen
}

