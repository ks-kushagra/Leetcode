There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int cycleExist(int n , vector <vector <int> > A , vector <int> &topo_order)
    {
          vector <int> indegree(n ,0);
          int visited =0;
          queue <int> q;
         
          for(int i=0;i<A.size();i++)
              indegree[A[i][0]]++;
        
         for(int i=0;i<n;i++)
         {
             if(indegree[i]==0)
             {
                 q.push(i);
                 topo_order.push_back(i);
             }
         }
        
        
        while(!q.empty())
        {
           int t = q.front();
            q.pop();
            visited++;
            
            for(int i=0;i<A.size();i++)
            {
                if(A[i][1]== t)
                {
                    indegree[A[i][0]]--;
                    if(indegree[A[i][0]]==0)
                    {
                        q.push(A[i][0]);
                        topo_order.push_back(A[i][0]);
                    }
                }
            }
        }
        
        if(visited == n)
            return 0;
        
        return 1;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& A) {
        
        vector <int> ans;
        if(cycleExist(n , A , ans))
            return vector <int> ();
        
        return ans;
    }
};
