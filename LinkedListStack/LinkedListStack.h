#pragma once
#include <iostream>
#include <cstdlib>
#define MAX 100
using namespace std;

typedef struct nodeRecord {
	int Data;
	struct nodeRecord* Next;
	struct nodeRecord* Prev;
}Node;

typedef Node* Nptr;

class StackClass {
public:
	StackClass();
	~StackClass();
	void Push(int Item);
	void Pop();
	int GetTop();
	bool IsEmpty();
	int GetSize();
	void ShowStack();
private:
	Nptr Head;
	int Count;
};