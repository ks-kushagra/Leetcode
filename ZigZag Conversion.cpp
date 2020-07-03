The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    string convert(string s, int numRows) {
        
    
        if(numRows <= 1)
            return s;
        int n = s.length();
        vector <string> t(numRows);
        int dir=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(dir == 0)
            {
                t[j].push_back(s[i]);
                if(j == numRows-1){
                    dir =1;
                    j--;
                }
                else
                    j++;
            }
            
            else if(dir == 1)
            {
                t[j].push_back(s[i]);
                if(j==0){
                    dir = 0;
                    j++;
                }
                else
                    j--;
            }
        }
        
        string ans="";
        for(int i=0;i<t.size();i++)
            ans = ans + t[i];
        
        return ans;
    }
};
