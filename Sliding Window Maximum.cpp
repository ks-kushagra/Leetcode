Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window.
Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
 ____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
       multiset <int> s;
        int n = A.size();
       vector <int> ans;
        for(int i=0;i<k;i++)
            s.insert(A[i]);
        
        ans.push_back(*(--s.end()));
        for(int i=k;i<n;i++)
        {
            int prev = A[i-k];
            s.erase(s.find(prev));
            s.insert(A[i]);
            ans.push_back(*(--s.end()));
        }
        
        return ans;
    }
};

________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& A, int k) {
        
        deque<int> dq;
        vector <int> ans;
        
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && A[dq.back()] < A[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        
        ans.push_back(A[dq.front()]);
        
        for(int i=k;i<A.size();i++)
        {
            while(!dq.empty() && (i-k) >= dq.front())
                dq.pop_front();
            
            while(!dq.empty() && A[dq.back()] <A[i])
                dq.pop_back();
            
            dq.push_back(i);
            ans.push_back(A[dq.front()]);
        }
        
        return ans;
    }
};
