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
    ListNode *h;
    void f(ListNode *i,ListNode *prev){
        if(!i){
            h = prev;
            return;
        }
        f(i->next,i);
        i->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        f(head,nullptr);
        head = h;
        return head;
    }
};