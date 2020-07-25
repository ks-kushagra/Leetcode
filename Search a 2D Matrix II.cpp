Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
__________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
     
        int n = A.size();
        if(n==0)
            return 0;
        int m = A[0].size();
        
        int i=0,j=m-1;
        while(i>=0 && i <n && j>=0 && j<m)
        {
            if(A[i][j]==target)
                return true;
            if(A[i][j]<target)
                i++;
            else
                j--;
        }
        
        return false;
    }
};
