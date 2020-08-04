Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
Follow up: Could you solve it without loops/recursion?
________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool isPowerOfFour(int num) {
      
        if(num == 1)
            return 1;
        if(num == 0)
            return 0;
        
        if(num % 2 !=0)
            return 0;
        
        if(num < 0)
            return 0;
        
        double a = log(num)/log(4);
        int b = a;
        if(a-b == 0)
            return 1;
        
        return 0;
    }
};
