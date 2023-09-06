class MyHashSet {
    vector<int> hashSet;
public:
    MyHashSet() {
        hashSet.resize(1000001, 0);
    }
    
    void add(int key) {
        if(!contains(key)) hashSet[key] = 1;
    }
    
    void remove(int key) {
        if(contains(key)) hashSet[key] = 0;
    }
    
    bool contains(int key) {
        return hashSet[key] == 1; 
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */