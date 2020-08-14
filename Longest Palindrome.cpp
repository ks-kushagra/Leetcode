Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    
    int longestPalindrome(string s) {
        unordered_map<char , int > mp;
        int ans=0;
        for(int i =0;i<s.length();i++)
            mp[s[i]]++;
        
        int flag=0;
 
        for(auto it=mp.begin();it != mp.end();it++)
        {
            if(it->second %2 == 0)
                ans += it->second;
            
            else
            {
                ans += it->second-1;
                flag=1;
            }
        }
        
        if(flag)
        return ans+1;
        
        return ans;
        
    }
};
