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
    bool hasCycle(ListNode *head) {
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
                return true ;
            }
        }
       return false; 
    }
};