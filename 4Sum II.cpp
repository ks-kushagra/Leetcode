Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0

_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map <int,int> mp1;
        unordered_map <int,int> mp2;
        int count=0;
        int n = A.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                mp1[A[i]+B[j]]++;
                mp2[C[i]+D[j]]++;
            }
        
        for(auto i =mp1.begin();i!=mp1.end();i++)
        {
            if(mp2.find((-1)*(i->first)) != mp2.end())
                count += (i->second)*mp2[(-1)*(i->first)];
        }
        return count;
    }
};
