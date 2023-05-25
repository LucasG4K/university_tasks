#include "queue.hpp"

Queue::Queue() {
	head = NULL;
	tail = NULL;
	size = 0;
}

int    Queue::getSize() { return size; }
Block* Queue::getHead() { return head; }
Block* Queue::getTail() { return tail; }

void Queue::inqueue(int value) {
	Block *block = (Block *)malloc(sizeof(Block));
	block->value = value;
	block->next  = NULL;

	if (head == NULL) {
		head = block;
		tail = block;
	} else {
		tail->next = block;
		tail = block;
	}
	size++;
}

Block* Queue::dequeue() {
	Block *temp;

	if(head == NULL) {
		cout << "FILA VAZIA!" << endl;
		return NULL;
	}

	temp = head;
	head = head->next;
    size--;
	return temp;
}

void Queue::reverse() {
	Block *curr = head;
	Block *prev = NULL;
	Block *next;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
}

// para testes
void Queue::print() {
	Block *temp;

    if (head == NULL) { cout << "FILA VAZIA!" << endl; return; }
    
	cout << "Fila: ";
	
	temp = head;
	while(temp != NULL) {
		cout << temp->value << "   ";
		temp = temp->next;
	}
    cout << endl;
}