
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x>0&&y>0)
        {
            ans +=(x&1)^(y&1);
            x=x/2;
            y=y/2;
        }
        
        while(x>0)
        {
            ans +=(x&1)^0;
            x=x/2;
        }
        
        while(y>0)
        {
            ans +=(y&1)^0;
            y=y/2;
        }
        return ans;
    }
};
