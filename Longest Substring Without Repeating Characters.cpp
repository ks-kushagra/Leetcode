Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
 _____________________________________________________________________________________________________________________________________________________________________________________________________________________________
 
 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length()==0)
            return 0;
        
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            unordered_map<char , int> freq;
            int cur=0;
            for(int j =i;j<s.length();j++)
            {
                if(freq.find(s[j]) == freq.end())
                    freq[s[j]]++,cur++;
                else
                    break;
                
            }
            ans = max(ans , cur);
        }
        
        return ans;
    }
};
