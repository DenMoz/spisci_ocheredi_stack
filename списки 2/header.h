#pragma once
struct orderList
{
	int id;						    // ����������������� ����� ������
	char name[30];					// ������������ ������� � ������
	int total;					    // ����� ���������� �������
	int usable;				        // ���������� ������ �������
	double percentage;				// ������� ������ �������
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
