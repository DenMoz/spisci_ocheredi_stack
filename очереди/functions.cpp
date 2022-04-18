#include<stdio.h>
#include<stdlib.h>
#include"Header.h"
NodePtr head = NULL;
NodePtr tail = NULL;
extern int menu()
{
	printf("1-�������� ������\n2-������� ������\n3-����� �� ���������\n");
	int operation;
	scanf_s("%d", &operation);
	printf("\n");
	return operation;

}

extern void addElement()
{
	NodePtr newNode = getData();
	newNode->next = NULL;
	if (head == NULL)
		head=newNode;
	else tail->next = newNode;

	tail = newNode;
}

static NodePtr getData()
{
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	printf("������� ������������ ������\n");
	getchar();
	gets_s(newNode->name);
	printf("������� ������ ���������� �������\n");
	scanf_s("%d", &newNode->total);
	printf("������� ���������� ������ �������\n");
	scanf_s("%d", &newNode->usable);
	const static int percent(100);
	newNode->percentage = (static_cast<double>(newNode->usable) / newNode->total) * percent;
	printf("������� ������ ������� ����� %lf\n", newNode->percentage);
	return newNode;
}

extern void deleteElement()
{
	NodePtr tempNode = head;
	if (head != NULL)
		head = head->next;
	if (head == NULL)
		tail = NULL;
	free(tempNode);
}

extern void display()
{
	NodePtr temp = head;
	if ( head== NULL)
		printf("������� �����.\n");
	else
	{
		printf("\n");
		printf("�   ��������  ����� ���-��  ���-�� ������  ������� ������\n");
		printf("******************************************************\n");
		int id = 1;
		while (temp != NULL)
		{
			temp->id = id;
			id++;
			printf("%d %s %12d %12d %20lf", temp->id, temp->name, temp->total,
				temp->usable, temp->percentage);
			printf("\n");
			temp = temp->next;
		}
		printf("\n");
	}
}