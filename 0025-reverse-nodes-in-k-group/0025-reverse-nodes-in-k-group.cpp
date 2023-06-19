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
    int len (ListNode* head){
        
        int count = 0 ;
        while(head != NULL){
            count++ ;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //if( k > len(head)) return head ;
        
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        
        ListNode *cur = head , *nxt , *prev = NULL ;
        
        int i = 0 ; 
        while(i <= k-1){
            
           // if(prev == NULL) head2 = head;
            nxt  = cur->next ;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            i++;
        }
        head->next = reverseKGroup(cur,k);
        return prev;
        
    }
};