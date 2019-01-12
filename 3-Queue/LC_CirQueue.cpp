class MyCircularQueue{
private:
	int q_size, p_front, p_rear;
	vector<int> data;
public:
	MyCircularQueue(int k) {
		data.resize(k + 1);
		p_front = 0;
		p_rear = 0;
		q_size = k + 1;
	}

	bool isFull() {
		return (p_rear + 1) % q_size == p_front;
	}

	bool isEmpty() {
		return p_rear == p_front;
	}

	bool enQueue(int value) {
		if(!isFull()) {
			data[p_rear] = value;
			p_rear = p_rear + 1 == q_size? 0: p_rear + 1;
			return true;
		}
		return false;
	}

	bool deQueue() {
		if(!isEmpty()) {
			p_front = p_front + 1 == q_size? 0: p_front + 1;
			return true;
		}
		return false;
	}

	int Rear() {
		if(isEmpty()) return -1;
		int rear = p_rear == 0? q_size - 1: p_rear -1;
		return data[rear];
	}

	int Front() {
		if(isEmpty()) return -1;
		return data[p_front];
	}

}

