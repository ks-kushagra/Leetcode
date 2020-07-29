Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int longestConsecutive(vector<int>& A) {
        int n = A.size();
        unordered_map<int,int> mp;
        if(n<=1)
            return n;
        
        for(int i=0;i<n;i++)
            mp[A[i]]++;
        
        int len =0;
        for(int i=0;i<n;i++)
        {
            int prev=A[i]-1;
            if(mp.find(prev) == mp.end())
            {
               int j = A[i];
                while(mp.find(j) != mp.end())
                     j++;
                
                len = max(len , j-A[i]);
            }
        }
            
        return len;
    }
};
