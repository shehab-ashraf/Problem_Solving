class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
    stack<ListNode*> s;
    vector<int> result;
    ListNode* ptr = head;
    while(ptr != NULL){
        while(!s.empty() && ptr->val > s.top()->val) {
            s.top()->val = ptr->val; 
            s.pop();
        }
        s.push(ptr);
        ptr = ptr->next;
    }
    while(!s.empty()) {
        s.top()->val = 0;
        s.pop();
    }
    while(head != NULL) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;       
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
