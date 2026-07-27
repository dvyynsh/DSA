#include <iostream>
#include <vector>
using namespace std;

// Problem StateMent
// Input: arr = [4, 7, 1, 0]
// Output = 7 1 0 

// Leader Means = The element Should Be greater than left element.
// for arr = [10, 22, 12, 3, 0, 6]  Leaders = 22 12 6.
// 6 because there is No element after 6 in right.

// 1. first pick one element i
// 2. Assume isLeader=true
// 3. then start comparing from j+1


vector<int> leaders(vector<int>& nums){
    vector<int> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++){
        bool isLeader = true;

        // Check all elements to the right
        for (int j = i + 1; j < n; j++){
            if (nums[j] > nums[i]){
                isLeader = false;
                break;
            }
        }

        if (isLeader){
            ans.push_back(nums[i]);
        }
    }

    return ans;
}


//--------------------------------------------------------------------------------------------------------------------------
// So we know Last element always will be the leader
// 1. We are going to start with last element compare {is secondLast > last}
// 2. No then 'secondLast' is not the leader.
// 3. Move left again.

#include <algorithm>


vector<int> leaders(vector<int>& nums){
    vector<int> ans;
    int n = nums.size();

    int maxRight = nums[n - 1];

    ans.push_back(maxRight);

    for (int i = n - 2; i >= 0; i--){
        if (nums[i] > maxRight){
            ans.push_back(nums[i]);
            maxRight = nums[i];
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}





