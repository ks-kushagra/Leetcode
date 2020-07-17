You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
___________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c = matrix[0].size();
        
       for(int i=0;i<r;i++)
           for(int j=i;j<c;j++)
               swap(matrix[i][j],matrix[j][i]);
        
       for(int i=0;i<r;i++)
            reverse(matrix[i].begin(),matrix[i].end());
        
        
    }
};
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int> >t(r,vector<int> (c,0));
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                t[r-1-j][c-1-i]=matrix[i][j];
            }
        
        reverse(t.begin(),t.end());
        matrix=t;
    }
};
