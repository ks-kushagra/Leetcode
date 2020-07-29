Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
_______________________________________________________________________________________________________________________________________________________________________________________________________________________-

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int>  mp;
       
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        for(auto it = mp.begin();it!=mp.end();it++)
            if((it->second) > (nums.size()/2))
                return it->first;
        
        return -1;
            
    }
};

______________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int candidate(vector <int> A , int n)
    {
        int max_index=0,count=1;
        for(int i=1;i<n;i++)
        {
            if(A[max_index] == A[i])
                count++;
            else
                count--;
            
            if(count == 0)
            {max_index=i;
             count=1;
            }
        }
        
        return A[max_index];
    }
    
    int isMajority(vector <int> A , int n , int cand)
    {
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(cand == A[i])
                c++;
            
            if(c > n/2)
                return 1;
        }
        
        return 0;
    }
    
    int majorityElement(vector<int>& nums) {
      
        int cand = candidate(nums,nums.size());
    
            if(isMajority(nums,nums.size(),cand))
                return cand;
        
        return -1;
            
    }
};
