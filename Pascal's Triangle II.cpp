Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        
        if(n == 0)
            return temp;
        
        temp.push_back(1);
        ans.push_back(temp);
        if(n==1)
         return temp;
        
        for(int i=2;i<=n;i++)
        {
            temp = vector<int>(i+1,1);
            for(int j=1;j<i;j++)
                temp[j] = ans[i-1][j] + ans[i-1][j-1];
            
            ans.push_back(temp);
        }
        
        return ans[n];
    }
};
