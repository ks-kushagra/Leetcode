Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.

________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        sort(A.begin(),A.end());
        priority_queue<pair<int, int> > pq;
        int freq=1;
        int n = A.size();
        
        for(int i=1;i<A.size();i++)
        {
            if(A[i]==A[i-1])
                freq++;
            else
            {
                pq.push({freq,A[i-1]});
                freq=1;
            }
        }
        
            pq.push({freq,A[n-1]});
        
        vector<int> ans;
        if(n==0)
            return ans;
        if(n==1)
        {   ans.push_back(A[0]);
            return ans;
        }
        
        while(k-- && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    } 
};
