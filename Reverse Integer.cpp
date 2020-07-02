Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of 
this problem, assume that your function returns 0 when the reversed integer overflows.

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    int reverse(int x) {
        int sign = 0;
        if(x < 0)
        {
            sign = 1;
            x = abs(x);
        }
        
        string s1 = to_string(x);
        string s ="";
        for(int i =0;i<s1.length();i++)
             s = s1[i] + s;
        
        long a = stol(s);
        
        if( (sign && (a-1) > INT_MAX) || (!sign && a > INT_MAX))
            return 0;
        
        return (sign ? (-1)*a : a);
    }
};
