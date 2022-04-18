#pragma once
struct Stack
{
	int id;						    // ����������������� ����� ������
	char name[30];					// ������������ ������� � ������
	int total;					    // ����� ���������� �������
	int usable;				        // ���������� ������ �������
	double percentage;				// ������� ������ �������
	Stack* next;
};
typedef Stack* StackPtr;

int menu();
void display();

void push();
void pop();
static StackPtr getData();
