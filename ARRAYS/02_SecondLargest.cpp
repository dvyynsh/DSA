#include <algorithm>  // for sort() 
#include <iostream>
using namespace std;


// Brute Force
// 1. Sort the array
// 2. Largest = Last Element
// 3. Traverse backwards
// 4. Return the first element smaller than the largest
int Brute(int arr[], int N){
  
  sort(arr, arr + N);

  int largest = arr[N-1];
  int secondLargest = -1;      
  // in case of arr is = {7,7,7,7,7} condition never became true But if array was {-4,-5,-10} then we do INT_MIN;

  for (int i=N-2; i>=0; i--){
    if(arr[i]!=largest){
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

//---------------------------------------------------------------------------------------------

// 0(N+N)
int Better(int arr[], int N){
  // First Traversal: Find Largest
  int largest = arr[0];
  for (int i = 1; i < N; i++){
    if (arr[i] > largest){
      largest = arr[i];
    }
  }

  // Second Traversal: Find Second Largest
  int secondLargest = -1;
  for (int i = 0; i < N; i++){
    if (arr[i] != largest && arr[i] > secondLargest){
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

//---------------------------------------------------------------------------------------------


int Optimal(int arr[], int N) {
    int largest = -1;
    int secondLargest = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}



int main()
{
    int arr[] = {1, 2, 4, 7, 7, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    int ans = Brute(arr, N);
    cout << "Second Largest = " << ans;

    return 0;
}