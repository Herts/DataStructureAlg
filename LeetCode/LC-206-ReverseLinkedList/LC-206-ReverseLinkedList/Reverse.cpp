#include<iostream>

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode * rHead = NULL;
		
		for (ListNode* node = head; node != NULL; node = node->next) {
			if (node == NULL) break;
			if (rHead == NULL) rHead = new ListNode(node->val);
			else
			{
				ListNode* tmp = new ListNode(node->val);
				tmp->next = rHead;
				rHead = tmp;
			}
		}

		return rHead;
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

	while (std::cin >> x) {
		if (x == -1) break;
		if (head == NULL) {
			cur = new ListNode(x);
			head = cur;
		}
		else addNode(cur, x);
	}

	ListNode * ret = Solution().reverseList(head);

}