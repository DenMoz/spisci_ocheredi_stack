#include<stdio.h>
#include"Header.h"
#include<stdlib.h>
int getNumber()
{
	printf("Введите число\n");
	int num;
	scanf_s("%d", &num);
	return num;
}

int menu()
{
	printf("\n1-Добавить данные в список\n2-Посчитать число элементов в списке\n3-вывести список на экран\n"
		"4-найти максимальный элемент списка\n5-найти минимальный элемент списка\n"
		"6-Удалить все повторения числа\n7-Удалить все вхождения числа\n8-Выйти из программы\n");
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
	else printf("Число %d не введено. Недостаточно памяти\n", num);
}

void printList(NodePtr startNode)
{
	if (startNode == NULL)
		printf("The list is empty.\n");
	else
	{
		printf("The list is :\n");
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
void findMax(NodePtr* startNode)
{
	NodePtr current, previous;
	int maxNum;
	current = (*startNode);
	previous = NULL;
	if (current == NULL)
	{
		printf("В списке нет элементов\n");
		exit(1);
	}
	maxNum = current->value;
	while (current != NULL)
	{
		if (maxNum < current->value)
			maxNum = current->value;
		previous = current;
		current = current->next;
	}
	printf("Максимальный элемент списка-%d\n", maxNum);
}
void findMin(NodePtr* startNode)
{
	NodePtr current, previous;
	int maxNum;
	current = (*startNode);
	previous = NULL;
	if (current == NULL)
	{
		printf("В списке нет элементов\n");
		exit(1);
	}
	maxNum = current->value;
	while (current != NULL)
	{
		if (maxNum > current->value)
			maxNum = current->value;
		previous = current;
		current = current->next;
	}
	printf("Максимальный элемент списка-%d\n", maxNum);
}
int deleteRep(NodePtr* startNode)
{
	if ((*startNode)->next == NULL) return 0;
	int kol = countList(startNode);
	NodePtr previous, current, temp;
	previous = (*startNode);
	int num = previous->value;
	current = (*startNode)->next;
	for (int counter = 1; counter < kol; counter++)
	{
		if (num == current->value)
		{
			temp = current;
			previous->next = current->next;
			free(temp);
			kol--;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	(*startNode) = (*startNode)->next;
	deleteRep(startNode);
}