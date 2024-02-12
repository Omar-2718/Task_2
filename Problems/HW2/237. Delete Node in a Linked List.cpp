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
    void deleteNode(ListNode* node) {
        ListNode *prev = nullptr;
        for(ListNode *i = node;i;i = i->next){
            if(i->next == nullptr)
            break;
            i->val = i->next->val; 
            prev = i;
        }
        prev->next = nullptr;


    }
};