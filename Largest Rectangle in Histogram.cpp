Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10

_______________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    
    //nearest Smaller left
    vector <int> NSL(vector <int> A)
    {
        int n = A.size();
        vector <int> nsl(n);
        stack<int> s;
        
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                nsl[i]=-1;
            
            else if(!s.empty() && A[s.top()]<A[i])
                nsl[i]=s.top();
            
            else if(!s.empty() && A[s.top()]>=A[i])
            {
                while(!s.empty() && A[s.top()]>=A[i])
                    s.pop();
                
                if(s.empty())
                    nsl[i]=-1;
                
                else
                    nsl[i]=s.top();
            }
            s.push(i);
        }
        
        return nsl;
    }
    
    vector <int> NSR(vector <int> A)
    {
        int n = A.size();
        vector <int> nsr(n);
        stack <int> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.empty())
                nsr[i]=n;
            
            else if(!s.empty() && A[i] > A[s.top()])
                nsr[i]=s.top();
            
            else if(!s.empty() && A[i] <= A[s.top()])
            {
                while(!s.empty() && A[i] <= A[s.top()])
                    s.pop();
                
                if(s.empty())
                    nsr[i]=n;
                else
                    nsr[i]=s.top();
            }
            
            s.push(i);
        }
        
        return nsr;
    }
    

    int largestRectangleArea(vector<int>& height) {
        vector <int> nsl = NSL(height);
        vector <int> nsr = NSR(height);
        int n = height.size();
        vector <int> width(n);
        
        for(int i=0;i<n;i++)
             width[i]=(nsr[i] - nsl[i] -1);

        
        int ans=0;
        for(int i=0;i<n;i++)
           ans = max(ans , height[i]*width[i]);
         
        return ans;
    }
};
