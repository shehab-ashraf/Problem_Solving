class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
	int counter = 1;
	ListNode *first = head;
	ListNode *second = head;
	while(counter <= k) {
		second = second->next;
		counter++;
	}
	if(second == NULL) {
                head = head->next;
		return head;
    }
	// while second is not NULL
	while(second->next != NULL){
		second = second->next;
		first = first->next;
	}
	// first is pointing to the node right before the node we want to remove
	// first->next = NODE_TO_REMOVE
	first->next = first->next->next;
        return head;
    }
};
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
