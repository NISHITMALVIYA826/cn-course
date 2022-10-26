/*

Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[].  

Note: Assume that you have an infinite supply of each type of coin. 

Examples: 

Input: sum = 4, coins[] = {1,2,3}, 
Output: 4
Explanation: there are four solutions: {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3}. 

Input: sum = 10, coins[] = {2, 5, 3, 6}
Output: 5
Explanation: There are five solutions: 
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.

*/


// Recursive C++ program for
// coin change problem.
#include <bits/stdc++.h>
using namespace std;
 
// Returns the count of ways we can
// sum coins[0...n-1] coins to get sum "sum"
int count(int coins[], int n, int sum)
{
 
    // If sum is 0 then there is 1 solution
    // (do not include any coin)
    if (sum == 0)
        return 1;
 
    // If sum is less than 0 then no
    // solution exists
    if (sum < 0)
        return 0;
 
    // If there are no coins and sum
    // is greater than 0, then no
    // solution exist
    if (n <= 0)
        return 0;
 
    // count is sum of solutions (i)
    // including coins[n-1] (ii) excluding coins[n-1]
    return count(coins, n - 1, sum)
           + count(coins, n, sum - coins[n - 1]);
}
 
// Driver code
int main()
{
    int i, j;
    int coins[] = { 1, 2, 3 };
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 4;
 
    cout << " " << count(coins, n, sum);
 
    return 0;
}
