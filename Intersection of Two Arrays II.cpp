Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]

Note:

    Each element in the result should appear as many times as it shows in both arrays.
    The result can be in any order.

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


________________________________________________________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    vector<int> intersect(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> mp;
        vector <int> ans;
        for(int i =0;i<A.size();i++)
            mp[A[i]]++;
        
        for(int i=0;i<B.size();i++)
            if(mp.find(B[i])!=mp.end() && mp[B[i]]!=0)
            {
                ans.push_back(B[i]);
                mp[B[i]]--;
            }
        
        return ans;
    }
};
