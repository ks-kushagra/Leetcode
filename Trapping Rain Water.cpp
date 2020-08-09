Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int trap(vector<int>& A) {
        int ans=0;
        int n =A.size();
        
        if(n<=1)
            return ans;
        
        vector <int> absleft(n,0);
        vector <int> absright(n,0);
        absleft[0]=A[0],absright[n-1]=A[n-1];
        for(int i=1;i<n;i++)
            absleft[i]=max(absleft[i-1],A[i]);
        
        for(int i=n-2;i>=0;i--)
            absright[i] = max(absright[i+1],A[i]);
        
        for(int i=0;i<n;i++)
            ans += min(absleft[i],absright[i])-A[i];
        
        return ans;
    }
};
