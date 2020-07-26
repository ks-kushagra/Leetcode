Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
____________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int minElement(vector<int> A)
    {
        int start =0,end = A.size()-1;
        int n = A.size();
        while(start <= end)
        {
            int mid = (start + (end -start)/2);
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(A[mid]<=A[prev] && A[mid]<=A[next])
                return mid;
            
            if(A[start]<=A[mid] && A[mid]<=A[end])
                return start;
            if(A[end]<=A[mid] && A[mid]<=A[start])
                return end;
            
            if(A[start] >= A[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        
        return -1;
    }
    
    int solve(vector <int>  A , int start , int end , int target)
    {
        while(start<=end)
        {
            int mid = (start + (end -start)/2);
            if(A[mid] == target)
                return mid;
            
            if(A[mid]>target)
                end = mid-1;
            else start = mid+1;
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index =  minElement(nums);
        if(index==-1)
            return -1;
        
        if(nums[index] == target)
            return index;
    
        int t1 = solve(nums,0,index-1,target);
        int t2 = solve(nums,index+1 ,nums.size()-1, target);
        
        if(t1!=-1)
            return t1;
        else
            return t2;
    }
};
