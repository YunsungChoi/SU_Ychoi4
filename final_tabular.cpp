// A Dynamic Programming based
// C++ program to partition problem
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Returns true if arr[] can be partitioned
// in two subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
 
    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];
 
    if (sum % 2 != 0)
        return false;
 
    bool part[sum / 2 + 1][n + 1];
 
    // initialize top row as true
    for (i = 0; i <= n; i++)
        part[0][i] = true;
 
    // initialize leftmost column,
    // except part[0][0], as 0
    for (i = 1; i <= sum / 2; i++)
        part[i][0] = false;
 
    // Fill the partition table in bottom up manner
    for (i = 1; i <= sum / 2; i++) {
        for (j = 1; j <= n; j++) {
            part[i][j] = part[i][j - 1];
            if (i >= arr[j - 1])
                part[i][j] = part[i][j]
                             || part[i - arr[j - 1]][j - 1];
        }
    }
 
    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */
 
    return part[sum / 2][n];
}
 

// Driver Code
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
