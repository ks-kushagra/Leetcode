Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

Follow up:

    A straight forward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?


________________________________________________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
       vector <pair<int,int> > v; 
       vector <int> row(r,1);
        vector <int> col(c,1);
        
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(matrix[i][j]==0)
                    v.push_back({i,j});
        
        for(int i=0;i<v.size();i++)
        {
            int x = v[i].first;
            int y = v[i].second;
            
            if(row[x]==1)
            {
                matrix[x]=vector <int> (c,0);
                row[x]=0;
            }
            
            if(col[y]==1)
            {
                for(int k=0;k<r;k++)
                    matrix[k][y]=0;
                
                col[y]=0;
            }
        }
    }
};
