struct Stack {
	int point;
	char* elems;

	Stack(int n) {
		point = -1;
		elems = new char[n];
	}
	~Stack() {
		point = -1;
		delete[] elems;
	}

	void push(double d) {
		point++;
		elems[point] = d;
	}
	double pop() {
		point--;
		return elems[point + 1];
	}
	void remove() {
		point--;
	}

	double back() {
		return elems[point];
	}
	int size() {
		return point + 1;
	}
	void clear() {
		point = -1;
	}

};
struct Queue {
	int point;
	char* elems;

	Queue(double n) {
		point = -1;
		elems = new char[n];
	}
	~Queue() {
		point = -1;
		delete[] elems;
	}

	void enqueue(double d) {
		point++;
		elems[point] = d;
	}
	double dequeue() {
		double d = elems[0];
		for (int i = 0; i < point; i++) {
			elems[i] = elems[i + 1];
		}
		point--;
		return d;
	}
	int size() {
		return point + 1;
	}
	void clear() {
		point = -1;
	}

};