#pragma once
struct queue
{
	int id;						    // идентификационный номер заказа
	char name[30];					// наименование деталей в заказе
	int total;					    // общее количество деталей
	int usable;				        // количество годных деталей
	double percentage;				// процент годных деталей
	struct queue* next;
};
typedef struct queue Node;
typedef Node* NodePtr;


extern int menu();

extern void addElement();
static NodePtr getData();
extern void deleteElement();
extern void display();