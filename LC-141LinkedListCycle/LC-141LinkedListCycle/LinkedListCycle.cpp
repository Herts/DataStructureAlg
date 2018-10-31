#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;
		
		ListNode* fast, * slow;
		fast = head->next;
		slow = head;

		while (fast != slow) {
			if (fast == NULL || fast->next == NULL) return false;

			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
	}
};

void addNode(ListNode*& node, int x) {
	ListNode* tmp = new ListNode(x);
	node->next = tmp;
	node = tmp;
}

int main(int argc, char** argv) {
	ListNode* head = new ListNode(1);
	ListNode* node = new ListNode(2);

	head->next = node;
	node->next = head;


	std::cout << Solution().hasCycle(head);

	system("pause");


}