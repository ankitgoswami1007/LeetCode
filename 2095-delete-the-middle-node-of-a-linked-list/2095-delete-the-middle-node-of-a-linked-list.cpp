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
    int length(ListNode* head){
        int i=0;
        while(head!=NULL){
            i++;
            head=head->next;
        }
        return i;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next == NULL) return NULL;
        
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        int len = length(head);
        if(len%2 == 0) slow->next = slow->next->next;
        else prev->next = slow->next;
        return head;
    }
};