#include<stdio.h>
#include"Header.h"
#include<stdlib.h>
int getNumber()
{
	printf("������� �����\n");
	int num;
	scanf_s("%d", &num);
	return num;
}

int menu()
{
	printf("\n1-�������� ������ � ������\n2-��������� ����� ��������� � ������\n3-������� ������ �� �����\n"
		"4-����� ������������ ������� ������\n5-����� ����������� ������� ������\n"
		"6-������� ��� ���������� �����\n7-������� ��� ��������� �����\n8-������������� ������\n0-����� �� ���������\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}

void input(NodePtr* startNode, int(*pointer)())
{
	int num = (*pointer)();
	NodePtr newNode, previous, current;
	newNode = (NodePtr)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->value = num;
		newNode->next = NULL;
		previous = NULL;
		current = (*startNode);
		while (current != NULL)
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
	else printf("����� %d �� �������. ������������ ������\n", num);
}

void printList(NodePtr startNode)
{
	if (startNode == NULL)
		printf("������ ����.\n");
	else
	{
		printf("������ :\n");
		while (startNode != NULL)
		{
			printf("%d-->", startNode->value);
			startNode = startNode->next;
		}
		printf("NULL\n");
	}
}

int countList(NodePtr* startNode)
{
	NodePtr current, previous;
	current = (*startNode);
	previous = NULL;
	if (current == NULL) return 0;
	if (current->next == NULL) return 1;
	int counter = 1;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
		counter++;
	}
	return counter;
}
int findMax(NodePtr* startNode)
{
	NodePtr current, previous;
	int maxNum;
	current = (*startNode);
	previous = NULL;
	if (current == NULL)
	{
		printf("� ������ ��� ���������\n");
		return 0;
	}
	maxNum = current->value;
	while (current != NULL)
	{
		if (maxNum < current->value)
			maxNum = current->value;
		previous = current;
		current = current->next;
	}
	printf("������������ ������� ������-%d\n", maxNum);
}
int findMin(NodePtr* startNode)
{
	NodePtr current, previous;
	int maxNum;
	current = (*startNode);
	previous = NULL;
	if (current == NULL)
	{
		printf("� ������ ��� ���������\n");
		return 0;
	}
	maxNum = current->value;
	while (current != NULL)
	{
		if (maxNum > current->value)
			maxNum = current->value;
		previous = current;
		current = current->next;
	}
	printf("������������ ������� ������-%d\n", maxNum);
}
void deleteRep(NodePtr root)
{
	NodePtr previous, startNode, current, temp;
	for (startNode = root; startNode != NULL; startNode = startNode->next)
	{
		previous = startNode;
		for (current = startNode->next; current != NULL;)
		{
			if (current->value == startNode->value)
			{
				previous->next = current->next;
				temp = previous->next;
				free(current);
				current = temp;
			}
			else
			{
				previous = current;
				current = current->next;
			}
		}
	}
}

void sort(NodePtr* startNode)
{
	int kol = countList(startNode);
	NodePtr current, previous;
	for (int iteration = 0; iteration < kol; iteration++)
	{
		previous = (*startNode);
		current = (*startNode)->next;
		while (current != NULL)
		{
			if (previous->value > current->value)
			{
				int temp = previous->value;
				previous->value = current->value;
				current->value = temp;
			}
			previous = current;
			current = current->next;
		}
	}
}

void deleteAll(NodePtr* root, int val, int kol)
{
	NodePtr previous, current, temp;
	for (int i = 0; i < kol; i++)
	{
		if (val == (*root)->value)
		{
			temp = (*root);
			(*root) = (*root)->next; // ����������� ����
			free(temp); // ���������� ������������� ����
		}
		else
		{
			previous = (*root);
			current = (*root)->next;
			while (current != NULL && current->value != val)
			{
				previous = current; /*�������.......*/
				current = current->next; /*...� ����������*/
			}
			if (current != NULL)
			{
				temp = current;
				previous->next = current->next;
				free(temp);
			}
		}
	}
}