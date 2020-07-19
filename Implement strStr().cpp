Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int strStr(string A, string B) {
        int n = A.length();
        int m = B.length();
        
        if(m==0)
            return 0;
        
        if(m>n)
            return -1;
        
        int i=0,j=0;
        int start=0;
        while(i<n && j<m)
        {
            
            if(A[i]==B[j])
            {
                i++;
                j++;
            }
            
            else
            {
                j=0;
                i=++start;
            }
        }
        
        if(j == m)
            return start;
        
        return -1;
        
    }
};
