//Count decodings of a given sequence of digits:
//Given a positive number, map its digits to the corresponding alphabet in the mapping table [(1, 'A'), (2, 'B'), … (26, 'Z')], and return the count of the total number of decodings possible. Assume that the input number can be split into valid single-digit or two-digit numbers that are present in the mapping table.//
#include <iostream>
#include <string>
using namespace std;
 
// Function to count the total decodings of a given sequence of digits
int count(string seq, int n)
{
    // base case
    if (n == 0 || n == 1) {
        return 1;
    }
 
    int sum = 0;
 
    // consider single-digit numbers (1, 2, … 8, 9)
    if (seq[n - 1] >= '1' && seq[n - 1] <= '9') {
        sum = count(seq, n - 1);
    }
 
    // consider 2-digit numbers (10, 11, … 19, 20, … 25, 26)
    if (seq[n - 2] == '1' || (seq[n - 2] == '2' && seq[n - 1] <= '6')) {
        sum += count(seq, n - 2);
    }
 
    return sum;
}
 
int main()
{
    int x = 1221;
 
    string seq = to_string(x);
    cout << "The total number of decodings are " << count(seq, seq.length()) << endl;
 
    return 0;
}
