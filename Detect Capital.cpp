Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
 

Example 1:

Input: "USA"
Output: True
 

Example 2:

Input: "FlaG"
Output: False
 
 
 ____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
 
 class Solution {
public:
    bool detectCapitalUse(string A) {
        
        int n = A.length();
        if(n<=1)
            return 1;
        

        int i=0;
        while(i<n && A[i]>='A' && A[i]<='Z')
            i++;
        
        if(i>1 && i<n)
            return 0;
        
        if(i == n)
            return 1;
        
        for(i=1;i<n;i++)
            if(A[i]>='A' && A[i]<='Z')
                return 0;
        
        return 1;
    }
};
