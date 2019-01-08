#include<iostream> 


struct ListNode {
	int val;
	ListNode *next;     
	ListNode(int x) : val(x), next(NULL) {}
 };

void insertAfter(ListNode* cur, int x) {
	if (cur == NULL) return;
	ListNode* tmp = new ListNode(x);
	tmp->next = cur->next;
	cur->next = tmp;
}


class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		// One is NULL or Two are NULL
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;

		// Find head -- node with smaller val
		ListNode* head = l2, *other = l1;

		if (l1->val < l2->val) {
				head = l1;
				other = l2;
		}

		ListNode *cur = head;
		while (cur != NULL || other != NULL) {

			// if one is NULL
			if (other == NULL) return head;
			if (cur->next == NULL) {
				cur->next = other;
				return head;
			}

			// Since l1 was compared with l2, 
			// there is no need that if(cur->val > other->val)
			if (cur->val == other->val) {
				insertAfter(cur, cur->val);
				cur = cur->next;
				other = other->next;

			}
			else{
				if(cur->next->val < other->val) cur = cur->next;
				else
				{
					insertAfter(cur, other->val);
					cur = cur->next;
					other = other->next;
				}
			}
		}
		return head;
	}
};



void addNode(ListNode *&cur, int x) {
	if (cur == NULL) return;
	ListNode * newNode = new ListNode(x);
	cur->next = newNode;
	cur = newNode;
}

int main(int argc, char** argv) {
	int x = 0;
	ListNode * head = NULL;
	ListNode * cur;
	ListNode * head2 = NULL;
	
	while (std::cin >> x) {
		if (x == -1) break;
		if (head == NULL) {
			cur = new ListNode(x);
			head = cur;
		}
		else addNode(cur, x);
	}

	while (std::cin >> x) {
		if (x == -1) break;
		if (head2 == NULL) {
			cur = new ListNode(x);
			head2 = cur;
		}
		else addNode(cur, x);
	}

	ListNode * ret = Solution().mergeTwoLists(head, head2);

}