/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head ;
        ListNode* fast = head ;
        bool f = false;
        
        while( fast != nullptr){
            fast = fast -> next;
            
            if(fast != nullptr){
                fast = fast -> next;
                slow = slow -> next;
            }
            if(slow == fast) {
                f = true;
                break ;
            }
        }
        int pos = 0;
        slow = head;
        if(f == true){
            while(slow != fast){
                slow = slow-> next;
                fast = fast-> next;
                pos++;
            }
            return slow ;
        }
        return nullptr ;
    }
};