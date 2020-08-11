Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.

________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    
    void LCS(string a , string b , int n , int m , vector <vector <int> > &t)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
    }
    string shortestCommonSupersequence(string a, string b) {
        
        int n = a.length() , m = b.length();
        string ans="";
        vector<vector <int>> t(n+1 , vector <int> (m+1 , 0));
        LCS(a,b,n,m,t);
        
        int i=n,j=m;
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                ans = a[i-1]+ans;
                i--;
                j--;
            }
            
            else if(t[i-1][j] > t[i][j-1])
                ans = a[i-1]+ans , i--;
            else
                ans = b[j-1]+ans , j--;
        }
        
        
        while(i>0)
            ans = a[i-1]+ans , i--;
        
        while(j>0)
            ans = b[j-1]+ans , j--;
        
        return ans;
        
    }
};
