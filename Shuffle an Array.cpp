Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();

__________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    vector<int> A;
    Solution(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
        A=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return A;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> t=A;
        
        for(int i=0;i<t.size();i++)
        {
            int k = i+ rand()%(t.size()-i);
            swap(t[i],t[k]);
        }
        
        return t;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
