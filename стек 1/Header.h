#pragma once
struct Stack
{
	int id;						    // идентификационный номер заказа
	char name[30];					// наименование деталей в заказе
	int total;					    // общее количество деталей
	int usable;				        // количество годных деталей
	double percentage;				// процент годных деталей
	Stack* next;
};
typedef Stack* StackPtr;

int menu();
void display();

void push();
void pop();
static StackPtr getData();
