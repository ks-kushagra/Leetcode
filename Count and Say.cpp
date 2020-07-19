The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    string countAndSay(int n) {
        
        if(n == 1)
            return "1";
        if(n==2)
            return "11";
        
        string s = "11";
        
        int c=1;
        
        for(int i=3;i<=n;i++)
        {
            s+='$';
            string t="";
          for(int j=1;j<s.length();j++){
              if(s[j]!=s[j-1])
              {
                t += c +'0';
                t += s[j-1];
                  c=1;
              }
              
              else
                  c++;
          }
            s=t;
        }
        return s;
    }
};
