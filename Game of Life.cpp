According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the 
following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every 
cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    
    int isSafe(vector<vector <int> > A , int i ,int j ,int n ,int m)
    {
      int dx[]={1,-1,0,0,1,-1,-1,1};
      int dy[]={0,0,-1,1,1,-1,1,-1};
        
        int live=0;
       for(int d=0;d<8;d++)
       {
           int x = dx[d]+i;
           int y = dy[d]+j;
           if(x>=0 && y>=0 && x<n && y<m)
           {
               if(A[x][y]==1)
                   live++;
           }
       }
        
        if(A[i][j]==0 && live==3)
            return 1;
        if(A[i][j]==1 && (live ==2 || live ==3))
            return 1;
        
        return 0;
    }
    void gameOfLife(vector<vector<int>>& A) {
        int n = A.size();
        if(n==0)
            return ;
        int m = A[0].size();
        vector <vector <int> > B( n , vector <int> (m ,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(isSafe(A,i,j,n,m))
                    B[i][j]=1;
            }
        
        A=B;
    }
};
