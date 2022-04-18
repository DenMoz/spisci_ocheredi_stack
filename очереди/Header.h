#pragma once
struct queue
{
	int id;						    // ����������������� ����� ������
	char name[30];					// ������������ ������� � ������
	int total;					    // ����� ���������� �������
	int usable;				        // ���������� ������ �������
	double percentage;				// ������� ������ �������
	struct queue* next;
};
typedef struct queue Node;
typedef Node* NodePtr;


extern int menu();

extern void addElement();
static NodePtr getData();
extern void deleteElement();
extern void display();