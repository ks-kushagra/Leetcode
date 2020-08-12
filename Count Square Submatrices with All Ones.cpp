Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int countSquares(vector<vector<int>>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        
         int m = A[0].size();
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(A[i][j] !=0)
                A[i][j] = min(A[i-1][j-1],min(A[i][j-1] ,A[i-1][j]))+1;
        
        int ans =0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans += A[i][j];
        
        return ans;
            
    }
};
