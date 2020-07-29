Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        int n = A.size();
        if(n == 0)
            return vector <int> ();
        
        int m = A[0].size();
        vector <int> ans(n*m);
        int k = 0;
        int t=0,b=n-1 ,l=0,r=m-1;
        int dir=0;
        
        while(k <n*m)
        {
            if(dir == 0)
            {
                for(int i=l;i<=r;i++)
                     ans[k++]=(A[t][i]);
                t++;
                dir=1;
            }
            
           else if(dir == 1)
            {
                for(int i=t;i<=b;i++)
                  ans[k++]=(A[i][r]);
                    
                r--;
                dir=2;
            }
            
            else if(dir == 2)
            {
                for(int i=r;i>=l;i--)
                    ans[k++]=(A[b][i]);
                b--;
                dir=3;
            }
            
            else if(dir == 3)
            {
                for(int i=b;i>=t;i--)
                    ans[k++]=(A[i][l]);
                l++;
                dir=0;
            }
        }
        
        return ans;
    }
};
