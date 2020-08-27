Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons.
If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right 
then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:

    int solve(vector <int> A , int i , int j , vector <vector <int> > &t)
    {
        if(i>j)
            return 0;
        
        int ans=INT_MIN;
        if(t[i][j] != -1)
            return t[i][j];
        
        for(int k=i;k<=j;k++)
        {
            int curr_profit = A[i-1]*A[k]*A[j+1];
            int temp = solve(A,i,k-1,t)+solve(A,k+1,j,t) + curr_profit;
            ans = max(ans , temp);
        }
        
        return t[i][j] = ans;
    }
    
    int maxCoins(vector<int>& A) {
        A.push_back(1);
        A.insert(A.begin() , 1);
        int n = A.size();
        vector <vector <int> > t(n+1 , vector <int> (n+1 ,-1));
        return solve(A , 1 , A.size()-2,t);
    }
};
