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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return head;
        }
        ListNode *tail = head;
        int n = 0;

        for(ListNode* i = head;i; i = i->next){
            n++;
            tail = i;
        }
        if(n == 1 || n == 0)
        return head;
        // rotate right 1 rotate left 4
        // rotate right k n-k
        for(int i =0;i< n - (k % n);i++){
            ListNode * t = head;
            head = head->next;
            tail->next = t;
            tail = t;
            tail->next = nullptr;
        }
        return head;
    }
};