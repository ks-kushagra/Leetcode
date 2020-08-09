Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int solve(string A, string B , int n , int m , vector<vector<int> > &t)
    {
        if(n==0)
            return m;
        if(m==0)
            return n;
        if(t[n][m] != -1)
            return t[n][m];
        
        if(A[n-1] == B[m-1])
            return t[n][m] = solve(A,B,n-1,m-1,t);
        
        return t[n][m] = 1 +min(solve(A,B,n-1,m,t),min(solve(A,B,n,m-1,t),solve(A,B,n-1,m-1,t)));
    }
    int minDistance(string A, string B) {
        int n = A.length() , m = B.length();
        vector<vector <int> > t(n+1 , vector <int> (m+1,-1));
        return solve(A,B,n,m,t);
    }
};
