class node{
    public:
    int key , value;
    node* prev;
    node* next;
    
    node(int k , int v):key(k),value(v),prev(NULL),next(NULL){}
};

class LRUCache {
    unordered_map <int, node*> cache ;
    int cap;
    node* left ;
    node* right ;
public:
    
    LRUCache(int capacity) {
        
        cap = capacity;
        left = new node(0,0);
        right =new node(0,0);
        
        left->next = right;
        right->prev = left;
    }
    void  removeAtLeft(node* n){
        node* nxt = n->next ;
        node* pre = n->prev;
        
        pre->next = nxt;
        nxt->prev = pre;
    }
    
    void insertAtRight(node* n){
        node* pre = right->prev;
        
        n->next = right ;
        n->prev = pre;
        right->prev = n;
        pre->next = n;
        
        
    }
    int get(int key) {
        
        if(cache.find(key) != cache.end()){
            removeAtLeft(cache[key]);
            insertAtRight(cache[key]);
            node* v = cache[key];
            return v->value ;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.find(key) != cache.end()){
            removeAtLeft(cache[key]);
        }
        node* newnode = new node(key , value);
        cache[key] = newnode;
        insertAtRight(cache[key]);
        
        if(cache.size() > cap){
            node* lru = left->next;
            removeAtLeft(lru);
            cache.erase(lru->key);
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */