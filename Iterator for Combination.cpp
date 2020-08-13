Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
A function next() that returns the next combination of length combinationLength in lexicographical order.
A function hasNext() that returns True if and only if there exists a next combination.
 

Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false

_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class CombinationIterator {
public:
    vector <string> ans;
    int it;
    void solve(string temp , int n , int curr,string A)
    {
        
        if(temp.length()==n)
        {
            ans.push_back(temp);
            return;
        }
        
        if(temp.length() > n)
            return ;
        
        for(int i=curr;i<A.length();i++)
        {
            temp.push_back(A[i]);
            solve(temp,n,i+1,A);
            temp.pop_back();
        }
    }
    CombinationIterator(string s, int n) {
        ans = vector<string> ();
        solve("",n,0,s);
        it=0;
    }
    
    string next() {
        if(it<ans.size())
         return ans[it++];
        
        return "";
    }
    
    bool hasNext() {
        if(it >= ans.size())
            return false;
        
        return true;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
