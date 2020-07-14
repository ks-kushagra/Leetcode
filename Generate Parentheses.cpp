 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

_____________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    
    int isValid(string s)
    {
        int c=0;    
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
                c++;
            
            else
                c--;
            
            if(c<0)
                return 0;
        }
        
        if(c!=0)
            return 0;
        
        return 1;
    }
    
    void solve(vector <string> &ans , int n , string temp)
    {
        if(temp.length() > 2*n)
            return;
        
        if( (temp.length()==2*n) && isValid(temp))
        {
            ans.push_back(temp);
            return;
        }
             
            if(temp.length() < 2*n )
            solve(ans,n,temp+"(");
        
            if(temp.length() < 2*n)
            solve(ans, n ,temp+")");
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        solve(ans,n,"");
        return ans;
    }
};
