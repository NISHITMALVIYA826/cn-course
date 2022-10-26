
/* 

A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. Implement a method to count how many possible ways the child can run up the stairs.

Examples: 

Input : 4
Output : 7
Explanation:
Below are the seven ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step 
 1 step + 1 step + 2 step
 2 step + 2 step
 3 step + 1 step
 1 step + 3 step

Input : 3
Output : 4
Explanation:
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step

*/

// A C++ program to count number of ways
// to reach n't stair when
#include <iostream>
using namespace std;

// A recursive function used by countWays
int countWays(int n)
{
	int res[n + 1];
	res[0] = 1;
	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i <= n; i++)
		res[i] = res[i - 1] + res[i - 2] + res[i - 3];

	return res[n];
}

// Driver program to test above functions
int main()
{
	int n = 4;
	cout << countWays(n);
	return 0;
}
