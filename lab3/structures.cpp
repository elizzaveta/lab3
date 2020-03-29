#include <string>
using namespace std;

class Stack {
	int point;
	string* elems;

public:
	Stack(int n) {
		point = -1;
		elems = new string[n];
	}
	~Stack() {
		point = -1;
		delete[] elems;
	}

	void push(string d) {
		point++;
		elems[point] = d;
	}
	string pop() {
		point--;
		return string(elems[point + 1]);
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
class Queue {
	int point;
	string* elems;

public:
	Queue(double n) {
		point = -1;
		elems = new string[n];
	}
	~Queue() {
		point = -1;
		delete[] elems;
	}

	void enqueue(string d) {
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