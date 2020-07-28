Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool canJump(vector<int>& nums) {
       //vector <int> t(nums.size(),-1);
        int n = nums.size();
        vector <int> t(n,0);
        t[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=nums[i];j>=1;j--)
            {
                if(i+j <n && t[i+j]==1)
                {
                    t[i]=1;
                    break;
                }
            }
        }
        return t[0];
    }
};
