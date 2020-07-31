Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells
connected horizontally or vertically.'

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________--

class Solution {
public:
    void dfs(vector <vector<char> > &A , int i , int j)
    {
        if(i<0 || j<0 || i>=A.size() || j>=A[0].size() || A[i][j] != '-')
            return;
        
        A[i][j]='O';
        
        dfs(A,i+1,j);
        dfs(A,i-1,j);
        dfs(A,i,j+1);
        dfs(A,i,j-1);
    }
    void solve(vector<vector<char>>& A) {
        int n = A.size();
        if(n==0)
            return ;
        
        int m = A[0].size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(A[i][j]=='O')
                    A[i][j]='-';
        
        
        
        for(int i=0;i<m;i++)
            if(A[0][i]=='-')
                dfs(A,0,i);
        
        for(int i=0;i<m;i++)
            if(A[n-1][i]=='-')
                dfs(A,n-1,i);
        
        for(int i=0;i<n;i++)
            if(A[i][0]=='-')
                dfs(A,i,0);
        
        for(int i=0;i<n;i++)
            if(A[i][m-1]=='-')
                dfs(A,i,m-1);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(A[i][j]=='-')
                    A[i][j]='X';
    }
};
