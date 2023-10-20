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
        if(head == NULL || head->next==NULL) return NULL;

        ListNode*slow = head;
        ListNode*fast = head;
        ListNode*entry = head;

        //1. detect the cycle in Linked list
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){ //if a cycle then chck for strting point
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry; //return strting point
            }
        }
        return NULL; //otherwise NULL
    }
};