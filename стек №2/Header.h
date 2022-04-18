#pragma once
struct Stack
{
	char* array;
	int arrSize;
	int head;
};
typedef Stack* StackPtr;

int getStackSize();
int initStack(StackPtr, const int);

int menu();

static bool isEmpty(StackPtr);
static bool isFull(StackPtr);

StackPtr chooseStack(StackPtr, StackPtr);
char getElement();
int push(StackPtr, char);
char pop(StackPtr);
int displayFirst(StackPtr);
int displaySecond(StackPtr);
void displayAll(StackPtr, StackPtr);

