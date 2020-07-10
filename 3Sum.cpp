Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector <vector <int> > ans;
        if(n<3)
            return ans;
        
        sort(nums.begin(),nums.end());
        int i=0;
        set<vector <int> > s;
        while(i < n-2)
        {
            int j = i+1;
            int k = n-1;
            while(j < k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0)
                {
                    vector <int> t(3);
                    t[0]=nums[i],t[1]=nums[j],t[2]=nums[k];
                        s.insert(t);
                    
                    j++;
                    k--;
                }
                
                else if(sum < 0)
                    j++;
                
                 else if(sum > 0)
                    k--;
                    
            }
            
            i++;
        }
        
        for(auto i = s.begin(); i!=s.end(); i++)
            ans.push_back(*i);
    
        return ans;
        
    }
};
