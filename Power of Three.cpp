Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false


______________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool isPowerOfThree(int n) {

    int start =0,end = n/3;
        while(start <= end)
        {
            int mid = (start + (end-start)/2);
            double p=pow(3.0 , mid);
            if(p==n)
                return 1;
            
            if(p>n)
                end=mid-1;
            else
                start = mid+1;
        }
        
        return 0;
    }
};
