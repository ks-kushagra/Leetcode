A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

 

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 10 ^ 9.

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    int solve(int m,int n , vector <vector <int> > &t)
    {
        if(m==1||n==1)
            return 1;
        
        if(m<0 || n<0)
            return 0;
        
        if(t[m][n] !=-1)
            return t[m][n];
        
        if(m-1 >0 && t[m-1][n] ==-1)
            t[m-1][n]=solve(m-1,n,t);
        
        if(n-1>0 && t[m][n-1] ==-1)
            t[m][n-1] = solve(m,n-1,t);
        
        return t[m-1][n]+t[m][n-1];
    }
    
    int uniquePaths(int m, int n) {
        
        if(m==1 && n==1)
            return 1;
        vector <vector <int> > t(m+1 , vector <int> (n+1 , -1) );
        return solve(m,n,t);
    }
};
