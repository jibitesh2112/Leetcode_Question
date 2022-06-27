#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
// Find the minimum product among all combinations of triplets in an array
int findMinTripletProduct(vector<int> A)        // no-ref, no-const
{
    // sort the given array in a natural order
    sort(A.begin(), A.end());
    int n = A.size();
 
    if (n <= 2) {
        return INT_MAX;
    }
 
    // consider the minimum among the product of the first three elements and
    // the product of the first element with the last two
    return min(A[n-1] * A[n-2] * A[0], A[0] * A[1] * A[2]);
}
 
int main()
{
    vector<int> A = { 4, -1, 3, 5, 9 };
 
    int min = findMinTripletProduct(A);
 
    if (min == INT_MAX) {
        cout << "No triplet exists since the vector has less than 3 elements";
    }
    else {
        cout << "The minimum product is " << min;
    }
 
    return 0;
}