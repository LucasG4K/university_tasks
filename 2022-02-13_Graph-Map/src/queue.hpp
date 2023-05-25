#ifndef QUEUE_HPP 
#define QUEUE_HPP

#include<iostream>
using namespace std;

typedef struct Item Item;
typedef struct Block Block;

struct Block {
	int value;
	Block *next;
};

class Queue {

private:
	Block *tail;
    int    size;
	Block *head;

public:
    Queue();
    void inqueue(int value);
    Block* dequeue();
    void reverse();
    void print();
    
    int    getSize();
    Block *getHead();
    Block* getTail();

};

#endif
