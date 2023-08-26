#include "LinkedListStack.h"

StackClass::StackClass() {
	Head = NULL;
	Count = 0;
}
StackClass::~StackClass() {
	while (!IsEmpty())
		Pop();
}
void StackClass::Push(int Item) {
	Nptr NewNode = new Node;
	NewNode->Data = Item;
	if (Count == 0) {
		NewNode->Next = NewNode;
		NewNode->Prev = NewNode;
	}
	else {
		NewNode->Next = Head;
		NewNode->Prev = Head->Prev;
		Head->Prev->Next = NewNode;
		Head->Prev = NewNode;
	}
	Head = NewNode;
	Count++;
}
void StackClass::Pop() {
	if (IsEmpty())
		cout << "Stack is Empty" << endl;
	else {
		Nptr DeleteNode = Head;
		Head->Next->Prev = Head->Prev;
		Head->Prev = Head->Next;
		Head = Head->Next;
		delete DeleteNode;
		Count--;
	}
}
int StackClass::GetTop() {
	return Head->Data;
}
bool StackClass::IsEmpty() {
	return Count == 0;
}
int StackClass::GetSize() {
	return Count;
}
void StackClass::ShowStack() {
	Nptr temp = Head;
	cout << "[ ";
	for (int i = 0; i < Count; i++) {
		temp = temp->Prev;
		cout << temp->Data << " ";
	}
	cout << "]" << endl;
}