A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    
    int solve(string a , int n , vector<int> &t)
    {
        if(n ==0 || a[0] == '0')
            return 0;
        
        if(n == 1)
            return 1;
        t[0]=1,t[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            if(a[i-1] !='0')
                t[i] =  t[i-1];
            
            if(a[i-2] == '1' || (a[i-1] <='6' && a[i-2] == '2'))
                t[i] += t[i-2];
        }
        
        return t[n];
    }
    int numDecodings(string s) {
        
        
       if(s == "" || s[0]=='0')
           return 0;
        
        vector <int> t(s.length()+1 , 0);
        
        return solve(s , s.length() , t);
        
    }
};
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
class Solution {
public:
    
    int solve(string a , int n , vector<int> &t)
    {
        if(n <1)
            return 0;
        
        if(n == 1 && a[n-1] !='0')
            return 1;
        
        
        if(a[n-1] == '0')
        {
            if(a[n-2] >'2'|| a[n-2] == '0')
                return 0;  
            
           if(n-2> 0)
            return t[n] = solve(a,n-2,t);
            
            else
                return 1;
        }
        
        if(n == 2)
        {
            if((a[n-1]>'0' && a[n-2]=='1') || (a[n-1]<='6' && a[n-2]=='2'))
                return 2;
            
            return 1;
        }
        
        if(t[n] !=-1)
            return t[n];
        
        int one = solve(a , n-1,t);
        int two =0;
        if(n-2 > 0)
        {
            if((a[n-1]>'0' && a[n-2]=='1') || (a[n-1]<='6' && a[n-2]=='2'))
                two = solve(a , n-2 ,t);
        }
        
        return t[n] = one+two;
    }
    int numDecodings(string s) {
        
        
       if(s == "" || s[0]=='0')
           return 0;
        
        vector <int> t(s.length()+1 , -1);
        
        return solve(s , s.length() , t);
        
    }
};
