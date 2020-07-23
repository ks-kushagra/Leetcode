Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    void solve(vector <int> A , int start , int end,vector<vector<int>> &ans)
    {
        if(start > end)
            return ;
        
        if(start == end )
            ans.push_back(A);

        for(int i=start;i<=end;i++)
        {
            swap(A[start],A[i]);
            solve(A,start+1,end,ans);
            swap(A[start],A[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector <vector <int> > ans;
        vector <int>  temp;
        solve(nums,0,nums.size()-1,ans);
        return ans;
    }
};
