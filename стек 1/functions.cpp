#include<stdio.h>
#include<stdlib.h>
#include"Header.h"
StackPtr top = NULL;

int menu()
{
	printf("1-�������� �������\n2-������� �������\n3-����� �� ���������\n");
	int operation;
	scanf_s("%d", &operation);
	printf("\n");
	return operation;
}

void push()
{
	StackPtr newElement = getData();
	newElement->next = top;
	top = newElement;
}
static StackPtr getData()
{
	StackPtr newNode = (StackPtr)malloc(sizeof(Stack));
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

void pop()
{
	StackPtr temp;
	if (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
}

void display()
{
	StackPtr temp = top;
	if (top == NULL)
		printf("C��� ����.\n");
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

