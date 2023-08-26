#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct NodeRecord {
	int Data;
	struct NodeRecord* Next;
	struct NodeRecord* Prev;
}Node;

typedef Node* Nptr;

class DLL {
public:
	DLL();
	~DLL();
	void Append(int Item);
	void Insert(int Position, int Item);
	void Delete(int Position);
	int int_Retrieve(int Position);
	void void_Retrieve(int Position, int* Itemptr);
	bool IsEmpty();
	int GetSize();
	int GetFront();
	int GetRear();
	void Showlist();
private:
	int Count;
	Nptr Head;
	Nptr Tail;
};
