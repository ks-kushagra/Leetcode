Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z=0,nz=0;
        if(n<=1)
            return;
        
        while(z<n && nums[z]!=0)
            z++;
        
        if(z==n)
            return;
        
        nz=z+1;
        while(nz<n && nums[nz]==0)
            nz++;
        
        for(int i=nz;i<n;i++)
        {
            if(nums[i]!=0)
                nums[z++]=nums[i];
        }
        
        while(z<n)
            nums[z++]=0;
    }
};
