Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.

_______________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int trailingZeroes(int n) {
        
        int ans=0 , i=0;
        if(n==0)
            return 0;
        while(n / pow(5 , i) > 0){
            ans += (n / pow(5 , i++));
        }
        
        return ans;
    }
};
