class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL; 
        ListNode *FastPointer = head;
        ListNode *SlowPointer = head;
        while(FastPointer != NULL && SlowPointer != NULL && FastPointer->next != NULL) {
            SlowPointer = SlowPointer->next;
            FastPointer = FastPointer->next->next;
            if(FastPointer == SlowPointer) break;
        }
        if(FastPointer == SlowPointer) {
            SlowPointer = head;
            while(SlowPointer != FastPointer) {
                SlowPointer = SlowPointer->next;
                FastPointer = FastPointer->next;
            }
            return SlowPointer;
        }
        return NULL;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
