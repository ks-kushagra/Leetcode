Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    void wiggleSort(vector<int>& A) {
        priority_queue<int> pq;
        
        for(int i=0;i<A.size();i++)
            pq.push(A[i]);
        
        for(int i=1;i<A.size(); i+=2)
            A[i]=pq.top(),pq.pop();
        for(int i=0;i<A.size();i+=2)
            A[i]=pq.top(),pq.pop();
    }
};
