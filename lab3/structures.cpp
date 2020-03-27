#include <string>
using namespace std;

struct Stack {
	int point;
	string* elems;

	Stack(int n) {
		point = -1;
		elems = new string[n];
	}
	~Stack() {
		point = -1;
		delete[] elems;
	}

	void push(double d) {
		point++;
		elems[point] = d;
	}
	string pop() {
		point--;
		return elems[point + 1];
	}
	void remove() {
		point--;
	}

	string back() {
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
	string* elems;

	Queue(double n) {
		point = -1;
		elems = new string[n];
	}
	~Queue() {
		point = -1;
		delete[] elems;
	}

	void enqueue(double d) {
		point++;
		elems[point] = d;
	}
	string dequeue() {
		string d = elems[0];
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