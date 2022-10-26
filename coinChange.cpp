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

// C++ program for coin change problem

#include <bits/stdc++.h>

using namespace std;

int count(int coins[], int n, int sum)
{
	int i, j, x, y;

	// We need sum+1 rows as the table
	// is constructed in bottom up
	// manner using the base case 0
	// value case (sum = 0)
	int table[sum + 1][n];

	// Fill the entries for 0
	// value case (sum = 0)
	for (i = 0; i < n; i++)
		table[0][i] = 1;

	// Fill rest of the table entries
	// in bottom up manner
	for (i = 1; i < sum + 1; i++) {
		for (j = 0; j < n; j++) {
			// Count of solutions including coins[j]
			x = (i - coins[j] >= 0) ? table[i - coins[j]][j]
									: 0;

			// Count of solutions excluding coins[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[sum][n - 1];
}

// Driver Code
int main()
{
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 4;
	cout << count(coins, n, sum);
	return 0;
}
