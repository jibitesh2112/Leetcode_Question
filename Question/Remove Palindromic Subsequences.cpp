class Solution {
public:
    int removePalindromeSub(string s) {
        // Check if string is empty
        if(s.empty())
            return 0;

        int len=s.size();

        // Check for pallindrome
        for(int i=0; i<=len/2; i++){
            // If not pallindrome then 2 operations are needed
            if(s[i] != s[len-i-1])
                return 2;
        }
        // If pallindrome then only one operation is needed
        return 1;
    }
};