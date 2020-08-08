Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

__________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int n = A.size();
        priority_queue<int , vector <int>  , greater<int> > pq;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                pq.push(A[i][j]);
        }
        
        while(--k)
          pq.pop();
        
        return pq.top();
    }
};
