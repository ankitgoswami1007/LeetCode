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
    ListNode* merge(ListNode* a , ListNode* b){
        
        if( a == NULL) return b;
        if( b == NULL) return a;
        
        ListNode* res ;
        
        if(a->val < b->val){
            res = a;
            res->next = merge(a->next , b);
        }
        else{
            res = b ;
            res->next = merge(a , b-> next);
        }
        return res;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
    /*    int n = lists.size();
        
        int last = n-1;
        
        while ( last != 0){
            
            int i = 0 , j = last;
            
            while( i < j){
                
                lists[i] = merge(lists[i] , lists[j]);
                i++ , j--;
                
                if(i >= j) last = j;
            }
        }
       return lists[0]; */
        if( lists.size()==0 ) return nullptr;
        
        while(lists.size() > 1){
            
            lists.push_back(merge(lists[0] , lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
//     struct compare {
//     bool operator()(const ListNode* l, const ListNode* r) {
//         return l->val > r->val;
//     }
// };
/*ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top();
    q.pop();
    if(result->next) q.push(result->next);
    ListNode* tail = result;            
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next) q.push(tail->next);
    }
    return result; 
} */
}; 