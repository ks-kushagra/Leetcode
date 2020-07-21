Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.


______________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    void checkPrime(vector<int> &A)
    {
        for(int i=2;i<A.size();i++)
        {
            if(A[i] == -1)
            {
                A[i]=1;
                int j=2*i;
                while(j<A.size())
                {
                        A[j]=0;
                    j=j+i;
                }
            }
        }
    }
    int countPrimes(int n) {
        
        vector<int> prime(n+1,-1);
        checkPrime(prime);
        
        int count=0;
        for(int i=2;i<n;i++)
            if(prime[i]==1)
                count++;
        
        return count;
    }
};
