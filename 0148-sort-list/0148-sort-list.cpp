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

	ListNode* mid(ListNode* head){
		ListNode* slow = head;
		ListNode* fast = head->next;

	while(fast){
		fast = fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	return slow;
}
    ListNode* merge(ListNode* a,ListNode* b){
	// Base case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}
	// Recursive Search
	ListNode* c;
	if(a->val < b->val){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c=b;
		c->next = merge(a,b->next);
	}
	return c;
}
ListNode* MergeSortLL(ListNode* head){
	// Base case
	if(head==NULL || head->next == NULL){
		return head;
	}
	// Recursive case
	// Divide
	ListNode* m = mid(head);
	ListNode* a = head;
	ListNode* b = m->next;
	m->next = NULL;
	// Sort
	a = MergeSortLL(a);
	b = MergeSortLL(b);
	// Merge
	ListNode* NayaHead = merge(a,b);
	return NayaHead;
}
public:
    ListNode* sortList(ListNode* head) {
        return MergeSortLL(head);
    }
};