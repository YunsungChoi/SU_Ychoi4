// A recursive C++ program for partition problem
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// A utility function that returns true if there is
// a subset of arr[] with sun equal to given sum
bool isSubsetSum(int arr[], int n, int sum,
				vector<vector<int> >& dp)
{
	// Base Cases
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;

	// return solved subproblem
	if (dp[n][sum] != -1) {
		return dp[n][sum];
	}

	// If last element is greater than sum, then
	// ignore it
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum, dp);

	/* else, check if sum can be obtained by any of
		the following
		(a) including the last element
		(b) excluding the last element
	*/
	// also store the subproblem in dp matrix
	return dp[n][sum]
		= isSubsetSum(arr, n - 1, sum, dp)
			|| isSubsetSum(arr, n - 1, sum - arr[n - 1],
							dp);
}

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
	// Calculate sum of the elements in array
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// If sum is odd, there cannot be two subsets
	// with equal sum
	if (sum % 2 != 0)
		return false;

	// To store overlapping subproblems
	vector<vector<int> > dp(n + 1,
							vector<int>(sum + 1, -1));

	// Find if there is subset with sum equal to
	// half of total sum
	return isSubsetSum(arr, n, sum / 2, dp);
}

// Driver code
int main()
{
int smallDataset[] = { 3, 1, 5, 9, 12 };
	int smallN = sizeof(smallDataset) / sizeof(smallDataset[0]);

	// Function call
	auto start = high_resolution_clock::now();
	if (findPartiion(smallDataset, smallN) == true)
		cout << "Can be divided into two subsets "
				"of equal sum" << endl;
	else
		cout << "Can not be divided into two subsets"
				" of equal sum"<< endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "recursion with small dataset: " << duration.count() << endl;
	
	int mediumDataset[] = {24,  3, 22, 53,  2, 88, 30, 38,  2, 64, 60, 21, 33, 76, 58, 22, 89,
        49, 91, 59, 42, 92, 60, 80, 15, 62, 62, 1, 9, 13};
	int mediumN = sizeof(mediumDataset) / sizeof(mediumDataset[0]);

	// Function call
	auto start1 = high_resolution_clock::now();
	if (findPartiion(mediumDataset, mediumN) == true)
		cout << "Can be divided into two subsets "
				"of equal sum"<< endl;
	else
		cout << "Can not be divided into two subsets"
				" of equal sum"<< endl;
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "recursion with medium dataset: " << duration1.count() << endl;


	int largeDataset[] = 
        {958, 563, 876, 567, 244, 832, 505, 131, 485, 819, 647,  21, 841,
        167, 274, 388, 601, 316,  14, 242, 777, 346, 565, 898, 340,  92,
        367, 956, 455, 428, 509, 776, 943,  35, 206,  81, 932, 562, 872,
        388,   2, 390, 566, 106, 772, 822, 477, 703, 402, 730, 556, 162, 1};
    /* {958, 563, 876, 567, 244, 832, 505, 131, 485, 819, 647,  21, 841,
        167, 274, 388, 601, 316,  14, 242, 777, 346, 565, 898, 340,  92,
        367, 956, 455, 428, 509, 776, 943,  35, 206,  81, 932, 562, 872,
        388,   2, 390, 566, 106, 772, 822, 477, 703, 402, 730, 556, 162, 1};
    */
	int largeN = sizeof(largeDataset) / sizeof(largeDataset[0]);
	// Function call

    auto start2 = high_resolution_clock::now();
	if (findPartiion(largeDataset, largeN) == true)
		cout << "Can be divided into two subsets "
				"of equal sum"<< endl;
	else
		cout << "Can not be divided into two subsets"
				" of equal sum"<< endl;
    auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "recursion with small dataset: " << duration2.count() << endl;
}
