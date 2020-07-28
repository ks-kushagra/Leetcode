Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int lengthOfLIS(vector<int>& A) {
        int n = A.size();
        vector <int> lis(n , 1);
        if(n==0)
            return 0;
        
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(A[i] > A[j] && lis[j]+1 > lis[i])
                {
                    lis[i] = lis[j]+1;
                    ans = max(ans , lis[i]);
                }
            }
        }
        
       return ans;
    }
};
