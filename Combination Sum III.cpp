Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    void solve(vector<vector <int> > &ans , vector <int> temp,vector <int> A  , int n , int k ,int sum , int curr)
    {
        
        if(temp.size() > k || sum > n)
            return ;
            
        if(temp.size() == k && sum == n)
        {
            if(find(ans.begin() , ans.end() , temp) == ans.end())
             ans.push_back(temp);
            
            return;
        }
        
        for(int i=curr;i<9;i++)
        {
            temp.push_back(A[i]);
            solve(ans , temp ,A , n , k , sum + A[i] , i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector <int> A;
        for(int i=1;i<=9;i++)
            A.push_back(i);
        
        vector<vector <int> > ans;
        vector <int> temp;
        solve(ans , temp ,A , n , k,0,0);
        return ans;
    }
};
