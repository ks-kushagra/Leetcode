Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& A) {
        
        unordered_map<string , vector <string> > mp;
        int n = A.size();
        vector< vector <string>> ans;
        
        for(int i=0;i<A.size();i++)
        {
            string s = A[i];
            sort(s.begin(),s.end());
            mp[s].push_back(A[i]);
        }
        
        if(mp.size() == 0)
            return ans;
        
        for(auto i =mp.begin();i!=mp.end();i++)
            ans.push_back(i->second);
        
        return ans;
        
    }
};
