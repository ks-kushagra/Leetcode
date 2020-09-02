Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        stack <char> s;
        stack <char> t;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='#' && !s.empty())
                s.pop();
            else if(S[i] !='#')
                s.push(S[i]);
        }
        
        for(int i=0;i<T.length();i++)
        {
            if(T[i] == '#' && !t.empty())
                t.pop();
            else if(T[i] != '#')
                t.push(T[i]);
        }
        
        if(s.size() != t.size())
            return 0;
        
        while(!s.empty() && !t.empty())
        {
            if(s.top() != t.top())
                return 0;
            
            s.pop();
            t.pop();
        }
        
        return 1;
    }
};
