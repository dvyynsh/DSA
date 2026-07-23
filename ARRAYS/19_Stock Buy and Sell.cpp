#include <iostream>
#include <vector>
using namespace std;

// Problem Statement
// You are given an array where: prices[i] => represents the stock price on the i-th day.

// Buy only once
// Sell only once
// Buy before you sell

// Find the maximum profit?

// Example prices = [7,1,5,3,6,4]
// Buy at: 1
// Sell at: 6
// Profit: 5
// You cannot: sell = 7 then Buy at 1
// Buying happens Before Selling!

// 1️⃣ Brute Force

// maxProfit = 0
// for each buy day i
//     for each sell day j (j > i)
//         profit = prices[j] - prices[i]
//         maxProfit = max(maxProfit, profit)

// return maxProfit/

// Example
// prices = [7, 1, 5, 3]
// Choose Buy Day = 0

// Buy = 7
// Sell = 1
// Profit = -6

// Sell = 5 
// Profit = -2

// Choose Buy Day = 1
// Buy = 1
// Sell = 5

int maxProfit(vector<int> &prices){
    int n = prices.size();

    // Initially, no profit.
    int maxProfit = 0;

    // Choose every day as the buying day.
    for (int i = 0; i < n; i++){
        // Choose every future day as the selling day.
        for (int j = i + 1; j < n; j++){
            // Calculate profit.
            int profit = prices[j] - prices[i];

            // Update maximum profit.
            maxProfit = max(maxProfit, profit);
        }
    }

    return maxProfit;
}


//---------------------------------------------------------------------------------------------------------------------------------------------

// 3️⃣ Optimal (Greedy)

// mini = first price
// maxProfit = 0

// for every price

//     profit = currentPrice - mini

//     maxProfit = max(maxProfit, profit)

//     mini = min(mini, currentPrice)

// return maxProfit

int maxProfit(vector<int> &prices){
    int mini = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++){
        // Profit if we sell today
        int profit = prices[i] - mini;

        maxProfit = max(maxProfit, profit);
        
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}