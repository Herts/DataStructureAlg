// slower than my first solution

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

        int i = 0;

        ListNode* fast = head;
        ListNode* pre = NULL;

        while(i++ < n ){
            fast = fast->next;
        }

        if(fast != NULL){
            pre = head;
            fast = fast->next;
        }
        else return head->next;

        while(fast != NULL){
            fast = fast->next;
            pre = pre->next;
        }

        pre->next = pre->next->next;

        return head;

    }
};
