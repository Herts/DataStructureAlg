class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Given that n is always valid,
        // result in NULL if there is only one node.
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* reverseHead = new ListNode(head->val);

        // Linked Stack
        for(ListNode* ni = head->next; ni != NULL; ni = ni->next){
            if(ni == NULL) break;
            ListNode* tmp = new ListNode(ni->val);
            tmp->next = reverseHead;
            reverseHead = tmp;
        }


        head = NULL;
        int count = 1;

        while(reverseHead != NULL){
            if(count == n){
                reverseHead = reverseHead->next;
                count++;
            }

            if(reverseHead == NULL) break;

            ListNode* tmp = new ListNode(reverseHead->val);
            tmp->next = head;

            head = tmp;
            reverseHead = reverseHead->next;
            count++;
        }

        return head;


    }
};
