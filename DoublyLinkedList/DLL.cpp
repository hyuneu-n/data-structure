#include "DLL.h"
//생성자
DLL::DLL() {
	Count = 0;
	Head = NULL;
}
//소멸자
DLL::~DLL() {
	while (!IsEmpty())
		Delete(1);
}
//마지막에 노드 추가
void DLL::Append(int Item) {
	Nptr NewNode = new Node;
	NewNode->Data = Item;
	NewNode->Next = NULL;

	if (Head == NULL) {
		Head = NewNode;
		Tail = NewNode;
		NewNode->Prev = Head;
	}
	else {
		Tail->Next = NewNode;
		NewNode->Prev = Tail;
		Tail = Tail->Next;
	}
	Count++;
}
//지정한 위치에 노드 삽입
void DLL::Insert(int Position, int Item) {
	Nptr NewNode = new Node;
	NewNode->Data = Item;
	if (Position<1 || Position>Count + 1)
		cout << "Out of Range" << endl;
	else {
		if (Position == 1) {
			NewNode->Next = Head;
			Head = NewNode;
			NewNode->Next->Prev = NewNode;
			NewNode->Prev = Head;
		}
		else if (Position == Count + 1) {
			Tail->Next = NewNode;
			NewNode->Prev = Tail;
			NewNode->Next = NULL;
		}
		else {
			Nptr tmp = Head;
			for (int i = 1; i < Position - 1; i++)
				tmp = tmp->Next;
			NewNode->Next = tmp->Next;
			tmp->Next = NewNode;
			NewNode->Next->Prev = NewNode;
			NewNode->Prev = tmp;
		}
		Count++;
	}
}
//지정한 노드 삭제
void DLL::Delete(int Position) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count)
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		Nptr DeleteNode = Head;
		if (Position == 1) {
			Head = tmp->Next;
			tmp->Next->Prev = NULL;
		}
		else if (Position == Count) {
			tmp = Tail->Prev;
			DeleteNode = tmp->Next;
			tmp->Next = NULL;
		}
		else {
			for (int i = 1; i < Position - 1; i++)
				tmp = tmp->Next;
			DeleteNode = tmp->Next;
			tmp->Next = DeleteNode->Next;
			DeleteNode->Next->Prev = tmp;
		}
		delete DeleteNode;
		Count--;
	}
}
//검색후 반환
int DLL::int_Retrieve(int Position) {
	if (IsEmpty()) {
		cout << "List is Empty" << endl;
		return 0;
	}
	else if (Position<1 || Position>Count) {
		cout << "Out of Range" << endl;
		return 0;
	}
	else {
		Nptr tmp = Head;
		for (int i = 1; i < Position; i++)
			tmp = tmp->Next;
		return tmp->Data;
	}
}
//검색 저장
void DLL::void_Retrieve(int Position, int* Itemptr) {
	if (IsEmpty())
		cout << "List is Empty" << endl;
	else if (Position<1 || Position>Count)
		cout << "Out of Range" << endl;
	else {
		Nptr tmp = Head;
		for (int i = 1; i < Position; i++)
			tmp = tmp->Next;
		*Itemptr = tmp->Data;
	}
}
//총 개수를 반환
int DLL::GetSize() {
	return Count;
}
//첫 노드의 data값을 반환
int DLL::GetFront() {
	if (IsEmpty()) {
		return -1;
	}
	else {
		return Head->Data;
	}
}
//마지막 노드의 data값을 반환
int DLL::GetRear() {
	if (IsEmpty()) {
		return -1;
	}
	else {
		return Tail->Data;
	}
}
//비어있는지 확인
bool DLL::IsEmpty() {
	return Count == 0;
}
//리스트 전체 출력
void DLL::Showlist() {
	cout << "[ ";
	Nptr tmp = Head;
	for (int i = 0; i < Count; i++) {
		cout << tmp->Data << " ";
		tmp = tmp->Next;
	}
	cout << "]" << endl;
}