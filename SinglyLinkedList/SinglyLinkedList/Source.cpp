#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class MyLinkedList {
	ListNode* head = new ListNode(0);
public:
	/** Initialize your data structure here. */
	MyLinkedList() {

	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		if (head->next == NULL) return -1;

		ListNode* cur = head->next;
		int count = 0;

		while (cur != NULL) {
			if (count == index) return cur->val;
			cur = cur->next;
			count++;
		}

		return -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		ListNode* tmp = new ListNode(val);

		if (head->next == NULL) head->next = tmp;
		else {
			tmp->next = head->next;
			head->next = tmp;
		}
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		ListNode* tmp = new ListNode(val);

		if (head->next == NULL) head->next = tmp;
		else {
			ListNode* cur = head->next;

			while (cur->next != NULL) cur = cur->next;

			cur->next = tmp;
		}

	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		if (index < 0) return;

		ListNode* cur = head;
		int count = 0;

		ListNode* tmp = new ListNode(val);

		while (cur != NULL) {
			if (count == index) {
				tmp->next = cur->next;
				cur->next = tmp;
				break;
			}
			else {
				cur = cur->next;
				count++;
			}
		}

	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		if (index < 0) return;

		ListNode* cur = head->next;
		ListNode* pre = head;

		int count = 0;

		while (cur != NULL) {
			if (count == index) {
				pre->next = cur->next;
				break;
			}
			else {
				cur = cur->next;
				pre = pre->next;
				count++;
			}
		}
	}
};

int main(int agrc, char** agrv) {
	MyLinkedList* obj = new MyLinkedList();

	
	obj->addAtHead(1);
	obj->addAtTail(3);
	obj->addAtIndex(1, 2);
	obj->deleteAtIndex(1);
}

