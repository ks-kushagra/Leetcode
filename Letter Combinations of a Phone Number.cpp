Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    void solve(vector<string> v , vector<string> &ans , string temp,string digit , int curr)
    {
        if(temp.length()==digit.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<v[digit[curr] - '0'].length();i++)
        {
            temp.push_back(v[digit[curr] - '0'][i]);
            solve(v,ans,temp,digit,curr+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector <string> v(10);
        v[0]="0",v[2]="abc",v[3]="def",v[1]="1",v[4]="ghi",v[5]="jkl",v[6]="mno";
        v[7]="pqrs",v[8]="tuv",v[9]="wxyz";
        
        vector <string> ans;
        if(digits.length()==0)
            return ans;
        
        solve(v,ans,"",digits,0);
        return ans;
    }
};
