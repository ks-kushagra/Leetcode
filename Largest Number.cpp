Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
___________________________________________________________________________________________________________________________________________________________________________________________________________-----

    bool compare(const string &a , const string &b)
    {
        string A = a+b;
        string B = b+a;
        
        return (A < B ? true:false);
    }
class Solution {
public:
    

    string largestNumber(vector<int>& nums) {
        
        vector <string> A;
        for(int i=0;i<nums.size();i++)
            A.push_back(to_string(nums[i]));
        
        sort(A.begin(),A.end(),compare);
        
        string ans="";
        
        for(int i=A.size()-1;i>=0;i--)
            ans += A[i];
        
        
        while(ans.length()>0 && ans[0]=='0')
            ans.erase(ans.begin());
        
        if(ans == "")
            return "0";
        
        return ans;
    }
};
