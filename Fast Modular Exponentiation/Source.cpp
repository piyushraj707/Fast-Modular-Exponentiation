#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int d) : data(d) {
		next = NULL;
	}
};

Node* head = NULL;
void insertTail(Node* &tail, int d) {
	if (tail == NULL) {
		tail = new Node(d);
		head = tail;
		return;
	}
	Node* temp = new Node(d);
	tail->next = temp;
	tail = temp;
}


int main() {

	long long b, n, m;

	cout << "This is the WORLD's fastest program to calculate b^n modulo m." << endl;
	cout << "Provide b: "; cin >> b;
	cout << "Provide n: "; cin >> n;
	cout << "Provide m: "; cin >> m; cout << endl;

	//finding binary equivalent of n in reverse order
	Node* tail = NULL;
	int q = n;
	while (q != 0) {
		insertTail(tail, q % 2);
		q = q / 2;
	}

	int result=1;
	int power = b % m;
	while (head != NULL) {
		if (head->data) result = (result * power) % m;
		power = (power * power) % m;
		head = head->next;
	}
	
	int len = (b * log(n)) / log(10) + 1;
	cout << "You provided a " << len << "-digit number and here is the result" << endl
		<< b << "^" << n << " mod " << m << " = " << result << endl;
	return 0;
}