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