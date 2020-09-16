Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    
    string poweroften(string A ,int n)
    {
        for(int i=0;i<n;i++)
             A.push_back('0');
        
        return A;
    }
    
    string add(string A , string B)
    {
        int i= A.length()-1;
        int j= B.length()-1;
        
        int car=0;
        string ans ="";
        while(i>=0 && j>=0)
        {
            int sum = car + (A[i]-'0') + (B[j]-'0');
            car = sum /10;
            ans = to_string(sum%10) + ans;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int sum = car  + (A[i]-'0');
            car = sum /10;
            ans = to_string(sum%10) + ans;
            i--;
        }
        
        while(j>=0)
        {
            int sum = car + (B[j]-'0');
            car = sum/10;
            ans = to_string(sum%10) + ans;
            j--;
        }
        
        
        if(car!=0)
            ans = to_string(car) + ans;
        
        return ans;
        
    }
    
    
    string muldigit(string A , char t)
    {
        int car=0;
        string ans= "";
        for(int i= A.length()-1; i>=0;i--)
        {
            int mul = (A[i]-'0')*(t-'0') + car;
            ans = to_string(mul %10) + ans;
            car = mul/10;
        }
        
        if(car != 0)
            ans = to_string(car) + ans;
        
        return ans;
    }
    
    string multiply(string A, string B) {
      
        string ans = "";
        int n = A.length();
        int m = B.length();
        
        if( (n == 1 && A[0] == '0') || (m==1 && B[0] == '0'))
             return "0";
        for(int i= n-1;i>=0;i--)
        {
            if(i == n-1)
                {
                    string t = muldigit(B , A[i]);
                    ans = add(ans , t);
                }
                
            else
            {
                string powten = poweroften(B , n - i -1);
                string t = muldigit(powten , A[i]);
                ans = add(ans , t);
            }
            
        }      
     return ans;
        
    }
};
