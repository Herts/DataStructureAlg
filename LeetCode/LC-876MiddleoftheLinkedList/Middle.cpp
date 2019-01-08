class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* reverseHead = new ListNode(head->val);

        double count = 1;

        for(ListNode* ni = head->next; ni != NULL; ni = ni->next){
            if(ni == NULL) break;

            ListNode* tmp = new ListNode(ni->val);
            tmp->next = reverseHead;
            reverseHead = tmp;

            count++;
        }
        
        head = NULL;

        for(double i = 0; i < count / 2; i++){
            ListNode* tmp = new ListNode(reverseHead->val);
            tmp->next = head;
            head = tmp;
            reverseHead = reverseHead->next;
        }

        return head;


    }
};
