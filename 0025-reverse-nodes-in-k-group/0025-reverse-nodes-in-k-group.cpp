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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == NULL) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *curr = dummy, *pre = dummy, *frwd = dummy;
        int count = 0;
        //count total no. of nodes in linkedlist
        while(curr->next != NULL){
            curr = curr->next;
            count++;
        }

        //if count is greater than k then only perform required operations
        while(count >= k){
            curr = pre->next; //curr is next node of dummy
            frwd = curr->next; //frwd is next node of curr i.e. 2nd node 
            for(int i=1; i<k; i++){
                curr->next = frwd->next;
                frwd->next = pre->next;
                pre->next = frwd;
                frwd = curr->next;
            }
            pre = curr;
            count -= k; //decrease the count once the k-group nodes are reverse
        }
        return dummy->next; //return dummy's next 
    }
};