
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


_________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector <int> > ans;
       
       for(int i=1;i<=n;i++)
       {
           vector <int> t(i,1);
           if(i==1||i==2)
               ans.push_back(t);
           else
           {
               for(int j=1;j<t.size()-1;j++)
                   t[j]=ans[i-2][j-1]+ans[i-2][j];
               
               ans.push_back(t);
           }
       }
        
        return ans;
    }
};
