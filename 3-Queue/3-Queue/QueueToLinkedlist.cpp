#include<iostream>

#define MAX 10


struct Node{
	int data;
	Node * next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

struct QuHead {
	Node * front;
	Node * rear;
	QuHead() {
		front = rear = NULL;
	}
};

bool isQuEmpty(QuHead* head) {
	return(head->rear == NULL);
}

void enQueue(QuHead *&head, int x) {
	Node * newNode = new Node(x);
	if (isQuEmpty(head)) {
		head->front = head->rear = newNode;

	}
	else {
		head->rear->next = newNode;
		head->rear = newNode;
	}
}

Node * Queue2Linkedlist(QuHead * headSet[]) {
	Node * linkedHead = new Node(-1);
	Node * tail = new Node(-1);
	bool isHeadAdded = false;

	for (int i = 0; i < MAX; i++) {
		QuHead * head = headSet[i];
		if (!isQuEmpty(head)) {
			if (!isHeadAdded) {
				linkedHead = head->front;
				isHeadAdded = true;
				tail = head->rear;
			}
			else
			{
				tail->next = head->front;

				tail = head->rear;
			}
			
		}
	}

	if (linkedHead->data != -1) {
		return linkedHead;
	}
}

void displayList(Node* node) {
	for (Node* tmp = node; tmp != NULL; node = node->next) {
		if (node != NULL) {
			std::cout << node->data << std::endl;
		}
		else
		{
			break;
		}
	}
}

int main() {
	
	QuHead * headSet[MAX];

	for (int i = 0; i < MAX; i++) {
		QuHead* tmp = new QuHead();
		headSet[i] = tmp;
	}
	
	std::cout << "Please input your numbers: " << std::endl;
	int x;
	while (std::cin >> x) {
		if (x>=0 && x <=9) {
			enQueue(headSet[x], x);
		}
		else if (x == -1) {
			break;
		}
	}

	Node* newNode = Queue2Linkedlist(headSet);

	displayList(newNode);
	
	delete[] newNode;

	system("pause");

}