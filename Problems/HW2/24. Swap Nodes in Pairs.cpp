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
    ListNode* swapPairs(ListNode* head) {

        if(!head){
            return head;
        }
        ListNode *prev = nullptr;
        ListNode *tem = head->next;
        bool d = false;
        for(ListNode *i = head ;i;){
            if(i == nullptr || i-> next == nullptr)
            break;
            ListNode *t = i -> next;
            i -> next = i->next->next;
            t -> next = i;
            d = true;
            if(prev)
            prev->next = t;
            prev = i;
            i = i->next;
        }
        if(d)
        head = tem;
        return head;
    }
};