Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701
 

Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    int titleToNumber(string s) {
        
        int ans =0;
        int n=s.length();
        int j=0;
        for(int i=n-1;i>=0;i--)
            ans +=pow(26,j++)*(s[i] -'A'+1);
        
        return ans;
    }
};
