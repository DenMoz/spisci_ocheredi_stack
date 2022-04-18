#pragma once
struct orderList
{
	int id;						    // идентификационный номер заказа
	char name[30];					// наименование деталей в заказе
	int total;					    // общее количество деталей
	int usable;				        // количество годных деталей
	double percentage;				// процент годных деталей
	orderList* next;
};
typedef orderList Node;
typedef Node* NodePtr;

extern int menu();

extern void input(NodePtr*);
NodePtr getdata();
extern void deleteData(NodePtr*);
extern void output(NodePtr);
extern void output_certain_data(NodePtr);

static void checkDetails(NodePtr);
