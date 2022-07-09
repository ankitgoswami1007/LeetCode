/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// -------------------- approach 1 with extra space

class Solution {
    unordered_map<Node* , Node*> mp;
    void insert(Node* cur, Node* &head, Node* &tail){
        if(head == NULL){
            Node* n = new Node(cur->val);
            head = tail = n;
            mp[cur] = n;
        }
        else{
            Node* n = new Node(cur->val);
            tail->next = n;
            tail = n;
            mp[cur] = n;
            
        }
    }
    
public:
    Node* copyRandomList(Node* head) {
        
        Node* cur = head;
        Node* head2 = NULL;
        Node* tail = NULL;
        while(cur){
            
            insert(cur, head2, tail);
            cur = cur->next;
            
        }
        cur = head;
        Node* nCur = head2;
        while(cur){
            nCur->random = mp[cur->random];
            nCur = nCur->next;
            cur = cur->next;
        }
        return head2;
    }
};  

//------------------------- approach 2 
/*class Solution {
    
    Node* duplicate(Node* cur, Node* head){
        
        while(cur){
            
            Node* temp = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = temp;
            cur = temp;
        }
        cur = head;
        return cur;
    }
    
public:
    Node* copyRandomList(Node* head) {
        
        Node* cur = head;
        cur = duplicate(cur, head);
        
        while(cur != NULL){
            if(cur->next){
                cur->next->random = cur->random != NULL ?cur->random->next: NULL;
            }
            cur = cur->next->next;
        }
        
        Node* original = head, *copy = head-> next, *temp = copy;
        
        while(original != NULL && copy != NULL){
            
            original->next = original->next->next;
            copy->next = (copy->next != NULL) ? copy->next->next  : copy->next;
            original = original->next;
            copy = copy->next;   
        }
        return temp;
    }
}; */