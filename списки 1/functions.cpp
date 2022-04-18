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
	printf("\n1-Добавить данные в список\n2-Посчитать число элементов в списке\n3-Вывести список на экран\n"
		"4-Найти максимальный элемент списка\n5-Найти минимальный элемент списка\n"
		"6-Удалить все повторения числа\n7-Удалить все вхождения числа\n8-Отсортировать список\n0-Выйти из программы\n");
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
		printf("Список пуст.\n");
	else
	{
		printf("Список :\n");
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
		printf("В списке нет элементов\n");
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
	printf("Максимальный элемент списка-%d\n", maxNum);
}
int findMin(NodePtr* startNode)
{
	NodePtr current, previous;
	int maxNum;
	current = (*startNode);
	previous = NULL;
	if (current == NULL)
	{
		printf("В списке нет элементов\n");
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
	printf("Максимальный элемент списка-%d\n", maxNum);
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
			(*root) = (*root)->next; // отсоединить узел
			free(temp); // освободить отсоединенный узел
		}
		else
		{
			previous = (*root);
			current = (*root)->next;
			while (current != NULL && current->value != val)
			{
				previous = current; /*перейти.......*/
				current = current->next; /*...к следующему*/
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