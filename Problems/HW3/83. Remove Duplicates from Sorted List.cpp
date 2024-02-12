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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        if(!head)
        return head;
        for(ListNode *i = head;i;i = i -> next){
            if(temp->val != i->val){
                temp->next = i;
                temp = i;
            }
        }
        temp->next = nullptr;
        return head;
    }
};