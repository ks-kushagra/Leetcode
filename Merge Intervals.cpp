Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        vector<vector<int> > ans;
        sort(A.begin(),A.end());
        int n = A.size();
        int i=0;
        int flag=0;
        while(i<n)
        {
            int j=i+1;
            int end=A[i][1];
            while(j<n && A[i][1] >= A[j][0])
            {
                flag=1;
                end =  max(end , A[j][1]);
                j++;
            }
            vector <int> t(2);
            t[0]=A[i][0];
            t[1]=end;
            ans.push_back(t);
            i=j;
        }
        if(flag)
        return merge(ans);
        
        return ans;
    }
};
