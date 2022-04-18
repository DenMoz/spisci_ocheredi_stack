#pragma once
struct list
{
	int value;
	struct list* next;
};
typedef struct list Node;
typedef Node* NodePtr;

int getNumber();
int menu();

void input(NodePtr*, int(*pointer)());
void printList(NodePtr);
int countList(NodePtr*);
int findMax(NodePtr*);
int findMin(NodePtr*);
void deleteRep(NodePtr);
void deleteAll(NodePtr*, int, int);
void sort(NodePtr*);
