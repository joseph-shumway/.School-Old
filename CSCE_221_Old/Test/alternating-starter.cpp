#include <iostream>
using std::cout;
using std::endl;

struct Node {
	Node* next;
	int data;
};

// DO NOT modify anything above this line!!!

void print_alternating(Node* node, bool other = true) {
	if (node != nullptr) {
		if (other) {
			other = false;
			cout << node->data << " ";
			print_alternating(node->next, other);
		} else {
			other = true;
			print_alternating(node->next, other);
		}
	}
	
}

// End of Code - Below here will be ignored when compiling

int main() {
    Node* node1 = new Node();
	node1->data = 1;
	Node* node2 = new Node();
	node2->data = 2;
	Node* node3 = new Node();
	node3->data = 3;
	Node* node4 = new Node();
	node4->data = 4;
	Node* node5 = new Node();
	node5->data = 5;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	print_alternating(node1);
}