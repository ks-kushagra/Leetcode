You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount.
If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.

______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:

    int coinChange(vector<int>& A, int B) {
        int n = A.size();
        vector <vector <int> >  t(n+1,vector <int> (B+1 , 0));
        
        for(int j=0;j<=B;j++)
            t[0][j]=INT_MAX-1;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=B;j++)
            {
                if(i == 1)
                {
                    if( j % A[i-1] == 0)
                        t[i][j]=j/A[i-1];
                    else
                        t[i][j]=INT_MAX-1;
                }
                
                else
                {
                    if(A[i-1] <= j)
                        t[i][j] = min(t[i-1][j] , t[i][j-A[i-1]] +1);
                    else
                        t[i][j]= t[i-1][j];
                }
            }
            
       if(t[n][B]==INT_MAX-1)
           return -1;
        
        return t[n][B];
    }
};
