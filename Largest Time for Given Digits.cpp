Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

 

Example 1:

Input: [1,2,3,4]
Output: "23:41"
Example 2:

Input: [5,5,5,5]
Output: ""
 

Note:

A.length == 4
0 <= A[i] <= 9
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    
    string timestartsTwo(vector <int> present)
    {
        string ans ="";
            ans = "2";
            present[2]--;
            int flag=0;
            for(int i=3;i>=0;i--)
                if(present[i])
                {
                 ans += to_string(i);
                 present[i]--;flag=1;
                 break;
                }
            
            if(flag==0)
                return "";
            ans = ans + ":";
            flag=0;
            for(int i=5;i>=0;i--)
            {
                if(present[i])
                {
                    ans += to_string(i);
                    present[i]--;
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
                return "";
            
            flag=0;
            for(int i=9;i>=0;i--)
                if(present[i])
                {
                    ans += to_string(i);
                    present[i]--;
                    flag=1;
                    break;
                }
            
            if(flag==0)
                return "";
        
        
        return ans;
    }
    
    string timestartsOne(vector <int> present)
    {
        string ans ="";
        
        
            ans = "1";
            present[1]--;
            int flag=0;
            
            for(int i=9;i>=0;i--)
                if(present[i])
                {
                    ans += to_string(i);
                    flag=1;
                    present[i]--;
                    break;
                }
            
            if(flag==0)
                return "";
            
            ans = ans + ":";
            flag=0;
            for(int i=5;i>=0;i--)
            {
                if(present[i])
                {
                    ans += to_string(i);
                    present[i]--;
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
                return "";
            
            flag=0;
            for(int i=9;i>=0;i--)
                if(present[i])
                {
                    ans += to_string(i);
                    present[i]--;
                    flag=1;
                    break;
                }
            
            if(flag==0)
                return "";
        
        return ans;
    }
    
    
 string timestartsZero(vector <int> present)
    {
        string ans ="";
        
            ans = "0";
            present[0]--;
            int flag=0;
            
            for(int i=9;i>=0;i--)
                if(present[i])
                {
                    ans += to_string(i);
                    flag=1;
                    present[i]--;
                    break;
                }
            
            if(flag==0)
                return "";
            
            ans = ans + ":";
            flag=0;
            for(int i=5;i>=0;i--)
            {
                if(present[i])
                {
                    ans += to_string(i);
                    present[i]--;
                    flag=1;
                    break;
                }
            }
            
            if(flag==0)
                return "";
            
            flag=0;
            for(int i=9;i>=0;i--)
                if(present[i])
                {
                    ans += to_string(i);
                    present[i]--;
                    flag=1;
                    break;
                }
            
            if(flag==0)
                return "";
            
            
        return ans;
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        
        vector <int> present(10 , 0);
        string ans="";
        for(int i=0;i<4;i++)
            present[A[i]]++;
        
        if(present[2])
        ans = timestartsTwo(present);
        if(ans != "")
            return ans;
        
        if(present[1])
        ans = timestartsOne(present);
        
        if(ans != "")
            return ans;
        
        if(present[0])
        ans = timestartsZero(present);
        
        if(ans != "")
            return ans;
        
        return "";
    }
};
