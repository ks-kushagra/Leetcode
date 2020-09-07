Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1
Example 2:

Input: A = [1,2], K = 4
Output: -1
Example 3:

Input: A = [2,-1,2], K = 3
Output: 3
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:

    int shortestSubarray(vector<int>& A, int K) {
       int n = A.size();
       int ans = INT_MAX;
        deque<int> dq;
        
        vector <int> prefixsum(n+1, 0);
        for(int i=1;i<=n;i++)
            prefixsum[i] = prefixsum[i-1]+A[i-1];
        
        for(int i=0;i<=n;i++)
        {
            while(!dq.empty() && prefixsum[i] - prefixsum[dq.front()] >=K)
                ans = min(ans , i - dq.front()) , dq.pop_front();
            
            while(!dq.empty() && prefixsum[i] <= prefixsum[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
    }
};
