class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Headpointer = new ListNode(0);
        ListNode *current = Headpointer;
        int carry = 0;
        auto *NodeOne = l1;
        auto *NodeTwo = l2;
        while(NodeOne != NULL || NodeTwo != NULL || carry != 0) {
            int ValueOne = NodeOne != NULL ? NodeOne->val : 0;
            int ValueTwo = NodeTwo != NULL ? NodeTwo->val : 0;
            int SumOfValues = ValueOne + ValueTwo + carry;
            int NewValue = SumOfValues % 10;
            auto *NewNode = new ListNode(NewValue);
            current->next = NewNode;
            current = NewNode;
            NodeOne = NodeOne != NULL ? NodeOne->next : NULL;
            NodeTwo = NodeTwo != NULL ? NodeTwo->next : NULL;
            carry =  SumOfValues / 10;
        }
        return Headpointer->next;
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
