Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
______________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    
    int isPalindrome(string s)
    {
        int i=0,j=s.length()-1;
        
        while(i<j)
        {
            if(s[i] != s[j])
                return 0;
            i++;
            j--;
        }
        
        return 1;
    }
    
    void solve(vector<vector <string> > &ans , vector <string> temp , int i , int j , string s)
    {
        if(i>=j)
        {
            ans.push_back(temp);
            return;
        }
    
        for(int k = i;k<j;k++)
        {
            if(isPalindrome(s.substr(i , k-i+1)))
            {
                temp.push_back(s.substr(i , k-i+1));
                solve(ans, temp , k+1 , j , s);
                temp.pop_back();
                
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector <string> > ans;
        vector <string> temp;
        solve(ans , temp , 0 , s.length(),s);
        return ans;
    }
};
