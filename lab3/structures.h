#pragma once


struct Stack {
	int point;
	int* elems;

	Stack(int n) {
		point = -1;
		elems = new int[n];
	}
	~Stack() {
		point = -1;
		delete[] elems;
	}

	void push(int d) {
		point++;
		elems[point] = d;
	}
	int pop() {
		point--;
		return elems[point + 1];
	}

	int back() {
		return elems[point];
	}
	int size() {
		return point + 1;
	}
	void clear() {
		point = -1;
	}

};
struct Queqe {
	int point;
	int* elems;

	Queqe(int n) {
		point = -1;
		elems = new int[n];
	}
	~Queqe() {
		point = -1;
		delete[] elems;
	}

	void enqueue(int d) {
		point++;
		elems[point] = d;
	}
	int dequeue() {
		int d = elems[0];
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