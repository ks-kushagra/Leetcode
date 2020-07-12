Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

Example 5:

Input: "{[]}"
Output: true


____________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        if(s.length()%2 != 0)
            return 0;
        
        int flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
                flag=1;
            }
            
            else
            {
                if(flag == 0 && st.empty())
                return 0;
                
                if(s[i] == ')')
                {
                    while(!st.empty() && st.top() !='(')
                        st.pop();
                    
                }
                
                else if(s[i] == ']')
                {
                    while(!st.empty() && st.top() !='[')
                        st.pop();
                    
                }
                
                else
                {
            
                   while(!st.empty() && st.top() !='{')
                        st.pop();
                     
                }
                
                if(st.empty())
                    return 0;
                else
                    st.pop();
                
            }
            
            if(st.empty())
                flag=0;
        }
        
        if(st.empty())
        return 1;
        
        else
            return 0;
    }
};
