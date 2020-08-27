Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

Note:

You may assume the interval's end point is always bigger than its start point.
You may assume none of these intervals have the same start point.
 

Example 1:

Input: [ [1,2] ]

Output: [-1]

Explanation: There is only one interval in the collection, so it outputs -1.
 

Example 2:

Input: [ [3,4], [2,3], [1,2] ]

Output: [-1, 0, 1]

Explanation: There is no satisfied "right" interval for [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point;
For [1,2], the interval [2,3] has minimum-"right" start point.
 

Example 3:

Input: [ [1,4], [2,3], [3,4] ]

Output: [-1, 2, -1]

Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
For [2,3], the interval [3,4] has minimum-"right" start point.

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& A) {
        
        int n = A.size();
        vector <int> ans(n);
        if(n==0)
            return vector <int> ();
        
        if(n==1){
            ans[0]=(-1);
            return ans;
        }
        
        for(int i=0;i<n;i++)
            A[i].push_back(i);
        
        sort(A.begin(),A.end());
        ans[A[n-1][2]]=-1;
        
        for(int i=0;i<n-1;i++)
        {
         if(A[i+1][0] >= A[i][1])
             ans[A[i][2]] = A[i+1][2];
         else
         {
             int j=i+1;
             while(j < n && A[j][0] < A[i][1])
                 j++;
             if(j == n)
                 ans[A[i][2]]=-1;
             else
                 ans[A[i][2]] = A[j][2];
         }
        }
        
        return ans;
    }
};
