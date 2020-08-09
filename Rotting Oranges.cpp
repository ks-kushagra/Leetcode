In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.

 

Example 1:



Input: [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: [[0,2]]
Output: 0
Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Note:

1 <= grid.length <= 10
1 <= grid[0].length <= 10
grid[i][j] is only 0, 1, or 2.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue <pair<pair<int,int> , int> > q;
        int n = grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({{i,j},0});
            }
        }

        int ans=0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first.first;
            int y = t.first.second;
            int level = t.second;
            ans = max(ans,level);
            if(x+1<n && grid[x+1][y]==1)
            {
                grid[x+1][y]=2;
                q.push({{x+1,y} , level+1});
            }
            
             if(x-1>=0 && grid[x-1][y]==1)
            {
                grid[x-1][y]=2;
                q.push({{x-1,y} , level+1});
            }
            
             if(y+1<m && grid[x][y+1]==1)
            {
                grid[x][y+1]=2;
                q.push({{x,y+1} , level+1});
            }
            
             if(y-1>=0 && grid[x][y-1]==1)
            {
                grid[x][y-1]=2;
                q.push({{x,y-1} , level+1});
            }
            
        }
        
        for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
                 if(grid[i][j]==1)
                     return -1;
        return ans;
        
    }
};
