There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
             
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& adj) {
        vector <vector <int> > graph(V , vector <int> (V , 0));
        for(int i=0;i<adj.size();i++)
        {
            int u = adj[i][1];
            int v = adj[i][0];
            graph[u][v]=1;
        }
        
        vector <int> indegree(V , 0);
        int visit =0;
        queue <int> q;
        for(int i=0;i<adj.size();i++)
            indegree[adj[i][0]]++;
        
        for(int i=0;i<V ; i++)
             if(indegree[i] == 0)
                 q.push(i);
        
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            visit++;
            
            for(int i=0;i<V;i++)
            {
                if(graph[t][i]==1)
                {
                    indegree[i]--;
                    if(indegree[i]==0)
                        q.push(i);
                }
            }
        }
        
        if(visit == V)
            return 1;
        
        return 0;
    }
};
