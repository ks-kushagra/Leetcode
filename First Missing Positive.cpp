Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int init(vector <int> &A ,int n)
    {
        int negative=n-1;
        for(int i=0;i<n;)
        {
            if(A[i] <= 0)
             swap(A[i],A[negative--]),n--;
            else 
                i++;  
        }
        return n;
    }
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();
        n = init(A,n);
        
        vector <int> B;
        for(int i=0;i<n;i++)
            B.push_back(A[i]);
        
        B.insert(B.begin(),0);
        for(int i=1;i<=n;i++)
        {
            if(abs(B[i])<=n && B[abs(B[i])]>0)
                B[abs(B[i])] = (-1)*B[abs(B[i])];
        }
        for(int i=1;i<=n;i++)
            if(B[i] > 0)
                return i;
        
        return n+1;
    }
};
