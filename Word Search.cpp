
___Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
_______________________________________________________________________________________________________________________________________________________________________________________________________________________

int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
class Solution {
public:
    /*
    int dfs(vector<vector <char> > grid , int i, int j , string word,int curr)
    {
        int n = grid.size();
        int m = grid[0].size();
        int len = word.length();
        
        
        if(i>=n || j>=m || i<0 || j <0 || grid[i][j] != word[curr] )
            return 0;
        
        if(curr+1 == len)
            return 1;
        
        char t = grid[i][j];
        grid[i][j]='#';
        int flag =0;
        
        if(!flag && i<n)
            flag = flag || (dfs(grid , i+1,j,word,curr+1));
        if(!flag && i>=0)
            flag = flag || dfs(grid , i-1 ,j,word,curr+1);
        if(!flag &&j>=0)
            flag = flag || dfs(grid , i ,j -1 , word , curr+1);
        if(!flag && j<m)
            flag = flag || dfs(grid , i,j+1 , word , curr+1);
        
        grid[i][j]=t;
        return flag;
        
    
    }
    bool exist(vector<vector<char>>& board, string word) {
       int n = board.size();
       int m = board[0].size();
        
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(word[0]==board[i][j])
               {
                   if(dfs(board , i,j,word,0))
                       return 1;
               }
           }
       }
        
        return 0;
    }*/
    
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (word == "")
            return true;
        if (board.size() == 0)
            return false;
        if (board[0].size() == 0)
            return false;
            
        for (int i = 0; i < board.size(); i++)  {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (DFS(board, word, i, j, 0))  {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool DFS(vector<vector<char> > &board, string word, int r, int c, int n)  {
        if (board[r][c] != word[n])
            return false;
            
        if (n + 1 == word.length())
            return true;
        
        board[r][c] -= 30;
        bool flag = false;
        if (!flag && r > 0)
            flag = flag || DFS(board, word, r - 1, c, n + 1);
        if (!flag && c > 0)
            flag = flag || DFS(board, word, r, c - 1, n + 1);
        if (!flag && r < board.size() - 1)
            flag = flag || DFS(board, word, r + 1, c, n + 1);
        if (!flag && c < board[0].size() - 1)
            flag = flag || DFS(board, word, r, c + 1, n + 1);
        board[r][c] += 30;
        
        return flag;
    }
};
