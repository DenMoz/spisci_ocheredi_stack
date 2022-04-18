#pragma once
struct Stack
{
	char* array;
	int arrSize;
	int head;
};
typedef Stack* StackPtr;

int getStackSize();
void initStack(StackPtr, const int);

int menu();

static bool isEmpty(StackPtr);
static bool isFull(StackPtr);

StackPtr chooseStack(StackPtr, StackPtr);
char getElement();
void push(StackPtr, char);
char pop(StackPtr);
void displayFirst(StackPtr);
void displaySecond(StackPtr);
void displayAll(StackPtr, StackPtr);

