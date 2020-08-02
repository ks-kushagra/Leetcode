Design a HashSet without using any built-in hash table libraries.

To be specific, your design should include these functions:

add(value): Insert a value into the HashSet. 
contains(value) : Return whether the value exists in the HashSet or not.
remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.

Example:

MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);          
hashSet.contains(2);    // returns true
hashSet.remove(2);          
hashSet.contains(2);    // returns false (already removed)
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class MyHashSet {
public:
    /** Initialize your data structure here. */
    int hash[1000001];
    MyHashSet() {
        memset(hash , -1 , sizeof(hash));
    }
    
    void add(int key) {
        hash[key]=1;
    }
    
    void remove(int key) {
        hash[key]=-1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(hash[key]==-1)
            return 0;
        
        return 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
