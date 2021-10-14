#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

LinkedList::~LinkedList() {
	delete head;
	delete tail;
}

LinkedList::LinkedList(const LinkedList& source) {
	delete head;
	delete tail;
	head = source.head;

	Node* temp = head;
	while (temp != nullptr) {
		if (temp->next == nullptr) {
			tail = temp;
		}
		temp = temp->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {

	LinkedList* newList = new LinkedList();
	newList->head->data = source.head->data;

	Node* temp = source.head;
	while (temp != nullptr) {
		newList->insert(temp->data.id, temp->data.year, temp->data.month, temp->data.temperature);
		temp = temp->next;
	}

	temp = newList->head;
	while (temp != nullptr) {
		if (temp->next == nullptr) {
			newList->tail = temp;
		}
		temp = temp->next;
	}

	return *newList;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function

	// check if the list is empty
	if (head == nullptr) {
		head = new Node(location, year, month, temperature);
		tail = head;
		//cout << "Adding initial value '" << head->data.id << "'" << endl << endl;
		return;
	}

	// check if the list has only one element and insert at the end
	if (head->next == nullptr) {
		//cout << "List has only one element '" << head->data.id << "'" << endl;
		Node* temp = new Node(location, year, month, temperature);
		if (*head < *temp) {
			head->next = temp;
			tail = temp;
			//cout << "Adding '" << temp->data.id << "' to the end" << endl << endl;
			return;
		} else {
			temp->next = head;
			tail = head;
			head = temp;
			//cout << "Adding '" << temp->data.id << "' to the beginning" << endl << endl;
			return;
		}
	}

	// move through list until the current node is less than the next node but greater than the previous node
	Node* nodeToInsert = new Node(location, year, month, temperature);
	Node* current = head;

	// if the node to insert is greater than the first element, set as the first element
	//if (*current > *nodeToInsert) {
	//	nodeToInsert->next = current;
	//	head = nodeToInsert;
	//	return;
	//}


	while (*current < *nodeToInsert) {
		//cout << "Current Node: " << current->data.id << "  " << current->data.year << " " << current->data.month << endl;
		if (current->next == nullptr) {
			break;
			//cout << "reached the end of the list!" << endl;
			current->next = nodeToInsert;
			nodeToInsert->next = nullptr;
			tail = nodeToInsert;
		}

		// if the next node is less than the node to insert, continue moving
		if (*current->next < *nodeToInsert) {
			//cout << "Current node '" << current->data.id << "' is less than '" << nodeToInsert->data.id << "'" << endl;
			//cout << "Keep moving..." << endl << endl;
			current = current->next;
		// else, stop here
		} else {
			//cout << "Stop!" << endl << endl;
			break;
		}
	}

	if (nodeToInsert->next != nullptr) {
		//cout << "Adding '" << nodeToInsert->data.id << "' before '" 
		//<< nodeToInsert->next->data.id << " " << nodeToInsert->next->data.year << "'" << endl << endl;
	} else {
		//cout << "Adding '" << nodeToInsert->data.id << "' as the tail" << endl << endl;
	}
	

	nodeToInsert->next = current->next;
	current->next = nodeToInsert;

}

void LinkedList::clear() {
	// Implement this function

	Node* current;
	while (head != nullptr) {
		current = head;
		head = head->next;
		current->next = nullptr;
		delete current;
	}

	head = nullptr;
	tail = nullptr;
	current = nullptr;
}

Node* LinkedList::getHead() const {
	return head;
}

string LinkedList::print() const {
	stringstream ss;
	Node* current = head;
	while (current != nullptr) {
		ss << current->data.id << " ";
		ss << current->data.year << " ";
		ss << current->data.month << " ";
		ss << current->data.temperature << "\n";
		current = current->next;
	}
	return ss.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}