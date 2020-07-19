Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________\


class Solution {
public:
    int firstUniqChar(string s) {
       
        unordered_map<char,pair<int,int> > mp;
        
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i]) != mp.end())
            {
                mp[s[i]]={mp[s[i]].first+1 ,mp[s[i]].second};
            }
           else
            mp[s[i]] = {1 , i}; 
        }
        
        
        int ans=s.length();
        for(auto it=mp.begin();it !=mp.end();it++)
            if( (it->second).first == 1)
                ans = min(ans , (it->second).second);
        
        
        if(ans == s.length())
            return -1;
        
        return ans;
    }
};
