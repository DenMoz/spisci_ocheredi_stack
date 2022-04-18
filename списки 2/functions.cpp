#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#pragma warning(disable:4996)
extern int menu()
{
	printf("1-�������� ������ � ������\n2-������� ������ � ������\n"
		"3-������� ������ � �������\n4-������� ������ � ���������� ������\n"
		"5-����� �� ���������\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}

extern NodePtr getData()
{ 
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	printf("������� ������������ ������\n");
	getchar();
	gets_s(newNode->name);
	printf("������� ������ ���������� �������\n");
	scanf_s("%d", &newNode->total);
	checkDetails(newNode);
	const static int percent(100);
	newNode->percentage = (static_cast<double>(newNode->usable) / newNode->total) * percent;
	printf("������� ������ ������� ����� %lf\n", newNode->percentage);
	return newNode;
}

extern void input(NodePtr* startNode)
{
	NodePtr newNode = getData();
	NodePtr previous, current;
	if (newNode != NULL)
	{
		newNode->next = NULL;
		previous = NULL;
		current = (*startNode);
		while (current != NULL && strcmp(newNode->name, current->name) > 0)
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL)
		{
			newNode->next = (*startNode);
			*startNode = newNode;
		}
		else
		{
			previous->next = newNode;
			newNode->next = current;
		}
	}
	else printf("������ �� �������. ������������ ������\n");
}

extern void output(NodePtr startNode)
{
	if (startNode == NULL)
		printf("The list is empty.\n");
	else
	{
		printf("\n");
		printf("�   ��������  ����� ���-��  ���-�� ������  ������� ������\n");
		printf("***********************************************************\n");
		int id = 1;
		while (startNode != NULL)
		{
			startNode->id = id;
			id++;
			printf("%d %s %12d %12d %20lf", startNode->id, startNode->name, startNode->total,
				startNode->usable, startNode->percentage);
			printf("\n");
			startNode = startNode->next;
		}
		printf("\n");
	}
}

extern void deleteData(NodePtr* startNode)
{
	NodePtr previous, current, temp;
	printf("������ id ������, ������� ������ �������\n");
	int id;
	scanf_s("%d", &id);
	if (id == (*startNode)->id)
	{
		temp =(*startNode);
		(*startNode) = (*startNode)->next;
		free(temp);
	}
	else
	{
		previous = (*startNode);
		current = (*startNode)->next;
		while (current != NULL && current->id != id)
		{
			previous = current;
			current = current->next; 
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
		}
	}
}

extern void output_certain_data(NodePtr startNode)
{
	if (startNode == NULL)
		printf("The list is empty.\n");
	else
	{
		printf("������� ����� ������, ������� ����� �������\n");
		int id;
		scanf_s("%d", &id);
		NodePtr current = startNode;
		while (current != NULL && id != current->id)
		{
			current = current->next;
		}
		if(current!=NULL)
		{
			printf("\n");
			printf("�   ��������  ����� ���-��  ���-�� ������  ������� ������\n");
			printf("***********************************************************\n");
			printf("%d %s %12d %12d %20lf", current->id, current->name, current->total,
				current->usable, current->percentage);
			printf("\n");
		}
		if (current == NULL) printf("����� ������ ���\n");
		printf("\n");
	}
}

static void checkDetails(NodePtr newNode)
{
	printf("������� ���������� ������ �������: ");
	scanf_s("%d", &newNode->usable);
	while (newNode->total < newNode->usable)
	{
		puts("���������� ������ ������� ������ ���� �� ������ �� ������ ����������. ������� ��� ��� ");
		scanf_s("%d", &newNode->usable);
	}
}
