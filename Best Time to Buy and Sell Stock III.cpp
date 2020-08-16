Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n =price.size();
        int buy1=INT_MAX , buy2 = INT_MAX , profit1=0,profit2=0;
        int i=0;
        while(i<n)
        {
            buy1 = min(buy1 , price[i]);
            profit1 = max(profit1 , price[i]-buy1);
            
            buy2 = min(buy2 , price[i]-profit1);
            profit2 = max(profit2 , price[i] - buy2);
            i++;
        }
        
        return (profit2);
    }
};
