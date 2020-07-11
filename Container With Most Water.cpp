Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at 
(i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int maxArea(vector<int>& A) {
     
        int n = A.size();
        int i=0;
        int j=n-1;
        int ans=0;
        int curr=0;
        while(i < j)
        {
            curr = min(A[i],A[j])*(j-i);
            ans = max(ans, curr);
            if(A[i] <= A[j])
              i++;
            else
                j--;
        }
     
        
        return ans;
    }
};
