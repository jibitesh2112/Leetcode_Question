#include <iostream>
#include <string>
using namespace std;
 
// Iterative function to calculate factorial of a number
int long factorial(int n)
{
    int long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    return fact;
}
 
// Function to find the lexicographic rank of a string
int long findLexicographicRank(string str)
{
    // rank starts from 1
    int long rank = 1;
 
    for (int i = 0; i < str.length() - 1; i++)
    {
        // count all smaller characters than `str[i]` to the right of `i`
        int count = 0;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] > str[j]) {
                count++;
            }
        }
 
        // add the current count to the rank
        rank += count * factorial(str.length() - 1 - i);
    }
 
    return rank;
}
 
int main()
{
    string str = "DCBA";
 
    cout << "The lexicographic rank of " << str << " is "
         << findLexicographicRank(str);
 
    return 0;
}