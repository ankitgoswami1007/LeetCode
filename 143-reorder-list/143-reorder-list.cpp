/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* head) {
        
        ListNode* next , *prev = nullptr , *cur = head;
        
        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur ;
            cur = next;
        }
        return prev ;
    }
    
         
public:
    void reorderList(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) return ;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev = head;
        
        while(fast && fast -> next){
            prev = slow ;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //prev->next = nullptr;
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow->next);
        slow->next = NULL;
        
        while(l2 != NULL) { 
             ListNode* temp1 = l1->next;
             ListNode* temp2 = l2->next;
             l1->next = l2;
             l2->next = temp1;
             l1 = temp1;
             l2 = temp2;
             
        }
        return;
    }
};