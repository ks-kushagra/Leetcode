There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        
        for(int i=0;i<B.size();i++)
            A.push_back(B[i]);
        sort(A.begin(),A.end());
        
        int n = A.size();
        if(n %2 ==0)
            return ( (A[n/2] + A[(n-1)/2])/2.0);
        return A[n/2.0];
    }
};
