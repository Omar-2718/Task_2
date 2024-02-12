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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // nth from back
        // 1 2 3 4 5 6
        // 6 5 4 3 2 1
        int length = 0;
        for(ListNode *i = head ; i ; i = i->next){
        length++;
        }

        // nth from start = n - nth from end + 1
        ListNode *prev = nullptr;
        ListNode *i = head;
        int nth = length - n + 1;
        for(int cnt = 1;cnt<=length;cnt++){
            if(cnt == nth)
            break;
            prev = i;
            i = i->next;

        }
        if(prev != nullptr){
            prev->next = i->next;
            delete i;
        }       
        else{
            ListNode *t = head;
            head = head->next;
            delete t;
        }
        return head;
    }
};