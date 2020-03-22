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