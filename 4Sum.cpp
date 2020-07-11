Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {    
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector <int> > s;
        int i=0;
        while(i < n-3)
        {
            int j=i+1;
            while(j < n-2)
            {
                int k = j+1;
                int l = n-1;
                
                while(k<l)
                {
                    int sum = nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum == target){
                    vector <int> t(4);
                    t[0]=nums[i];
                    t[1]=nums[j];
                    t[2]=nums[k];
                    t[3]=nums[l];
                    s.insert(t);
                        k++;
                        l--;
                    }
                    
                    else if(sum > target)
                        l--;
                    else
                        k++;
                }
                j++;
            }
            i++;
        }
        
        return vector <vector <int> >(s.begin(),s.end());
    }
};
