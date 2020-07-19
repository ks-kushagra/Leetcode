Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
____________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    string addBinary(string a, string b) {
        
        int i=a.length()-1,j=b.length()-1;
        string ans="";
        if(a=="")
            return b;
        if(b == "")
            return a;
        
        int c=0;
        while(i>=0 && j>=0)
        {
            int sum = (a[i]-'0') + (b[j] - '0')+c;
            c=sum/2;
            ans = to_string(sum%2)+ans; 
            i--;
            j--;
        }
        

            while(i>=0)
            {
                int sum = (a[i]-'0')+c;
                c=sum/2;
                ans =  to_string(sum%2)+ans;
                i--;
            }
            
        while(j>=0)
            {
                int sum = (b[j]-'0')+c;
                c=sum/2;
                ans =  to_string(sum%2) + ans;
                j--;
            }
        
        if(c)
            ans = "1"+ans;
        return ans;
    }
};
