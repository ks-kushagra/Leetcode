Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, 
and (r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], K = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    void init(vector<vector <int> > &ans , vector <vector <int> > mat , int n , int m)
    {
        // copying first Row
        for(int i=0;i<m;i++)
            ans[0][i] = mat[0][i];
        
        //Summing all colums
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
             ans[i][j] = mat[i][j] + ans[i-1][j];
        
        for(int i=0;i<n;i++)
            for(int j=1;j<m;j++)
                ans[i][j] += ans[i][j-1];
    
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        const int m = mat.size(), n = mat[0].size();
        auto vsum = vector(m+1, vector(n+1, 0)), res = vector(m, vector(n, 0));
        for(int i=0; i<m;i++) for(int j=0; j<n; j++)
            vsum[i+1][j+1] = vsum[i+1][j] + vsum[i][j+1] - vsum[i][j] + mat[i][j];
        for(int i=0; i<m;i++) for(int j=0; j<n; j++)
        {
            int i1 = max(0, i-K), i2 = min(i+K+1, m), j1 = max(0, j-K), j2 = min(j+K+1, n);
            res[i][j] = vsum[i2][j2] - vsum[i1][j2] - vsum[i2][j1] + vsum[i1][j1];
        }        
        return res;
    }
};
