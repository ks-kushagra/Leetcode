Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    long long int max(long long int a , long long int b)
    {return (a >= b ? a : b);}
    
    int maxProduct(vector<int>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        
        long long int ans = INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            long long int prod=1;
            for(int j=i;j<n;j++)
            {
                prod = prod*A[j];
                ans = max(ans , prod);
            }
        }
        
        return ans;
    }
};
