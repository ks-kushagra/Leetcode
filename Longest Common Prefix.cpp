Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    string prefix(string a , string b)
    {
        string s="";
        int i=0,j=0;
        while(i<a.length() && j<b.length())
        {
            if(a[i] != b[j])
                break;
            
            s=s+a[i];
            i++;
            j++;
        }
        
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        if(n==0)
            return "";
        if(n==1)
            return strs[0];
        
        string s = prefix(strs[0],strs[1]);
        
        for(int i=2;i<n;i++)
            s = prefix(s , strs[i]);
        
        return s;
    }
};
