#include <iostream>
using namespace std;

int CheackDuplicacy(int arr[], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[i]==arr[j]){
                return false;
            }
        }
    }
    return true;
}