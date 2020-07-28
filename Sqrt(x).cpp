Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
             
_______________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int mySqrt(int x) {
    
        if(x<1)
            return 0;
         if(x==1)
             return 1;
        long long int a =0;
       for(a = 0;a*a<=x;a++);
         
        return a-1;
    }
};
_______________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int mySqrt(int x) {
    
        if(x<1)
            return 0;
         if(x==1)
             return 1;
        long long int a =0;
       long long int b=0;
        while(a*a <= x)
        {
            a++;
        }
        
        return a-1;
    }
};
