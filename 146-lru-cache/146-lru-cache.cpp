class LRUCache {
    class Node{
    public:
        int key ;
        int value ;
        Node* prev;
        Node* next;
        public:
        Node(int k, int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    int capacity ;
    Node* head, *last ;
    unordered_map<int, Node*> cache;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0,0);
        last = new Node(0,0);
        
        head->next = last;
        last->prev = head;
        
    }
    
    int get(int key) {
        
        if(cache.find(key) != cache.end()){
            Node* n = cache[key];
            
            remove(n);
            insert(n);
            return n->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        if(cache.size() == capacity){
            remove(last->prev);
        }
        insert(new Node(key , value));
        
    }
    
    void insert(Node* node){
        int key = node->key;
        cache[key] = node;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        
    }
    
    void remove(Node* node){
        cache.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */