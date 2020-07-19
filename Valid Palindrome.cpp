Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
 

Constraints:

s consists only of printable ASCII characters.
_______________________________________________________________________________________________________________________________________________________________________________________________________________________________-


class Solution {
public:
    
    int isValid(char a)
    {
        if((a>='a' && a<='z') || (a>='A' && a<='Z') || (a>='0' && a<='9'))
            return 1;
        
        return 0;
    }
    bool isPalindrome(string s) {
        
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(isValid(s[i]) && isValid(s[j]))
            {
                if(s[i]>='0' && s[i]<='9' && s[j]>='0' && s[j]<='9'){
                    if(s[i] != s[j])
                        return 0;
                }
                else
                {
                    if(tolower(s[i]) != tolower(s[j]))
                        return 0;
                }
                
                i++;
                j--;
            }
            
            else if(!isValid(s[i]))
                i++;
            else
                j--;
                
        }
        
        return 1;
    }
};
