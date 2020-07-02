Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        
        map<int,int> mp;
        
        int n = A.size();
        
        for(int i=0;i<n;i++)
            mp.insert({target - A[i] , i});
        
        vector <int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(A[i]) != mp.end() && i != mp[A[i]])
            {
                if(i < mp[A[i]])
                {ans.push_back(i);
                 ans.push_back(mp[A[i]]);
                 
                }
                
                else
                {
                    ans.push_back(mp[A[i]]);
                    ans.push_back(i);
                }
                
                break;
            }
        }
        
        return ans;
    }
};
