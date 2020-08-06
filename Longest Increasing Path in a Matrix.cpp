Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________



___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________



              --------------------------Time Limit Exceeded (A possible solution)---------------------------------
              
              
              
 class Solution {
public:
    
    int solve(vector<vector <int> > A , int n , int m, int i ,int j)
    {
        if(i>=n || j>=m || i< 0 || j < 0 )
            return 0;
        
        int a=0,b=0,c=0,d=0;
        
        if(i+1 < n && A[i+1][j] > A[i][j] )
            a = 1 + solve(A , n ,m,i+1 , j);
        
        if(i-1 >=0 && A[i-1][j] > A[i][j])
            b = 1 + solve(A , n ,m ,i-1 ,j);
        
        if(j+1 < m && A[i][j+1] > A[i][j])
            c = 1 + solve(A , n,m,i,j+1);
        
        if(j-1 >=0 && A[i][j-1] > A[i][j])
            d = 1 + solve(A , n , m , i ,j-1);
        
        
        return max(a , max(b ,max(c,d)));
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        if(n==0)
            return 0;
        
        int m = matrix[0].size();
        int ans =0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                ans  = max(ans, solve(matrix ,n,m ,i,j));
            }
        return ans+1;
    }
};
