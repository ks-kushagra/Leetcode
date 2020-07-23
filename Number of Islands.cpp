Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    //No of Connected Components in a graph
    
    void DFS(vector<vector <char> > &grid,int i,int j,vector<vector <int> > &visited)
    {
        if(i<0||j<0 || i>=grid.size()||j>=grid[0].size()||visited[i][j]==1||grid[i][j]!='1')
            return ;
        visited[i][j]=1;
        grid[i][j]='-';
        DFS(grid,i+1,j,visited);
        DFS(grid,i-1,j,visited);
        DFS(grid,i,j+1,visited);
        DFS(grid,i,j-1,visited);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        vector<vector <int> > visited(n , vector <int> (m , 0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                    DFS(grid , i , j , visited) , ans++;
            }
        
        return ans;
    }
};
