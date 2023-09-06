class MyHashSet {
    vector<list<int>> hashSet;
    int siz;
public:
    MyHashSet() {
        siz = 100;
        hashSet.resize(siz);
    }
    int hash(int key) {
        return key%siz;
    }
    list<int> :: iterator search(int key){
        int i = hash(key);
        return find(hashSet[i].begin(), hashSet[i].end(), key);
    }
    void add(int key) {
        if(contains(key)) return;
        int i = hash(key);
        hashSet[i].push_back(key);
    }
    
    void remove(int key) {
        if(!contains(key)) return;
         int i = hash(key);
         hashSet[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        return search(key) != hashSet[i].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */