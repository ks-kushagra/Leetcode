On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int solve(vector <int > A , int curr , int n,vector <int> &t)
    {
        if(curr >= n)
            return 0;
        if(curr == n-1)
            return A[curr];
        
        if(t[curr] !=-1)
            return t[curr];
        
        return t[curr] =A[curr] + min(solve(A , curr+1 , n,t) , solve(A, curr+2 , n,t));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        if(n==0)
            return 0;
        
        if(n == 1)
            return cost[0];
        
        vector <int> t(n+1,-1);
        int zero = solve(cost , 0,n,t);
        t=vector <int> (n+1,-1);
        int one = solve(cost , 1, n,t);
        return min(zero,one);
    }
};
