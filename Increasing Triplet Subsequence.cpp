Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool increasingTriplet(vector<int>& A) {
        int n = A.size();
        if(n<3)
            return 0;
        
        int first = INT_MAX/*first smallest till now*/ , second = INT_MAX /*second smallest till now*/;
        for(int i=0;i<n;i++)
        {
            if(A[i]<=first)
                first=A[i];
            else if(A[i]<=second)
                second = A[i];
            else
                return 1;
        }
     
        return 0;
    }
};
