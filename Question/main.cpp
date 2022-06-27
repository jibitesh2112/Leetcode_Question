#include <bits/stdc++.h>
using namespace std;

/* C++ program to Check if a given array contains duplicate
elements within k distance from each other */
bool checkDuplicatesWithinK(int arr[], int n, int k)
{

	// traversing the input array
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		int range = k;
		// searching in next k-1 elements if its duplicate
		// is present or not
		while (range > 0 and j < n) {
			if (arr[i] == arr[j])
				return true;
			j++;
			range--;
		}
	}
	return false;
}

// Driver method to test above method
int main()
{
	int arr[] = { 10, 5, 3, 4, 3, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (checkDuplicatesWithinK(arr, n, 3))
		cout << "Yes";
	else
		cout << "No";
}

// This article is contributed by Arpit Jain
