class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        int carry = 0;
        ListNode* Headpointer = new ListNode(0);
        auto NodeOne = l1;
        auto NodeTwo = l2;
        while(NodeOne != NULL) {
            s1.push(NodeOne->val);
            NodeOne = NodeOne->next;
        }
        while(NodeTwo != NULL) {
            s2.push(NodeTwo->val);
            NodeTwo = NodeTwo->next;
        }
        while(!s1.empty() || !s2.empty() || carry != 0) {
            int ValueOne = !s1.empty() ? s1.top() : 0;
            int ValueTwo = !s2.empty() ? s2.top() : 0;
            int ResultOfSum = ValueOne + ValueTwo + carry;
            ListNode* NewNode = new ListNode(ResultOfSum%10);
            NewNode->next = Headpointer != NULL ? Headpointer->next : NULL;
            Headpointer->next = NewNode;
            carry =  ResultOfSum/10;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
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
    
