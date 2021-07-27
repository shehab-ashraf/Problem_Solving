class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *FastPointer = head;
        ListNode *SlowPointer = head;
        while(FastPointer != NULL && SlowPointer != NULL && FastPointer->next != NULL) {
            SlowPointer = SlowPointer->next;
            FastPointer = FastPointer->next->next;
            if(FastPointer == SlowPointer) return true;
        }
        return false;
        
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
