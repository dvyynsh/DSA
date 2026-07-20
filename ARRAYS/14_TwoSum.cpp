#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> Brute(vector<int>& arr, int target){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] + arr[j] == target){
                return {i, j};
            }
        }
    }
    // No valid pair found.
    return {-1, -1};
}

//------------------------------------------------------------------------------------------------------------------
// Using Map
// Arr = [1,2,3,4,5] && target = 3
// for i=0 -> got "1"
// need = 3-1 = 2
// is "2" already there in map? Nope -> Store the current element
// map 1 => 0
// i=1 -> got "2"
// need = 3 - 2 = 1
// is "1" already there in map? Yes -> Return {map[1],1}

// 1. Calculate the required number.
// 2. Check if it already exists in the map.
// 3. If YES -> Pair Found.
// 4. If NO  -> Store the current element.

vector<int> Better(vector<int>& arr, int target)
{
    map <int, int> mp;   // { Element, key}

    for(int i = 0; i < arr.size(); i++){
        int need = target - arr[i];

        // Check if the required number already exists.
        if(mp.find(need) != mp.end()){
            return {mp[need], i};
        }

        // Store the current number with its index.
        mp[arr[i]] = i;
    }

    return {-1, -1};
}

//------------------------------------------------------------------------------------------------------------------

// This approch only works if asked YES or No We can't return indices.
// 1. Sort the array.
// 2. Place one pointer at the beginning.
// 3. Place one pointer at the end.
// 4. Compute the sum.
// 5. If sum == target, return YES.
// 6. If sum < target, move the left pointer.
// 7. If sum > target, move the right pointer.
// 8. Repeat until left < right

string twoSum(vector<int>& arr, int target){
    sort(arr.begin(), arr.end());

    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target){
            return "YES";
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }

    return "NO";
}
