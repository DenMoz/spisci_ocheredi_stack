#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"
#pragma warning(disable:4996)
extern int menu()
{
	printf("1-Добавить данные о заказе\n2-Удалить данные о заказе\n"
		"3-Вывести данные о заказах\n4-Вывести данные о конкретном заказе\n"
		"5-Выход из программы\n");
	int operation;
	scanf_s("%d", &operation);
	return operation;
}

extern NodePtr getData()
{ 
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	printf("Введите наименование заказа\n");
	getchar();
	gets_s(newNode->name);
	printf("Введите полное количество деталей\n");
	scanf_s("%d", &newNode->total);
	checkDetails(newNode);
	const static int percent(100);
	newNode->percentage = (static_cast<double>(newNode->usable) / newNode->total) * percent;
	printf("Процент годных деталей равен %lf\n", newNode->percentage);
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
	else printf("Данные не введены. Недостаточно памяти\n");
}

extern void output(NodePtr startNode)
{
	if (startNode == NULL)
		printf("The list is empty.\n");
	else
	{
		printf("\n");
		printf("№   Название  Общее кол-во  Кол-во годных  Процент годных\n");
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
	printf("Ввести id записи, которую хотите удалить\n");
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
		printf("Введите номер записи, которую нужно вывести\n");
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
			printf("№   Название  Общее кол-во  Кол-во годных  Процент годных\n");
			printf("***********************************************************\n");
			printf("%d %s %12d %12d %20lf", current->id, current->name, current->total,
				current->usable, current->percentage);
			printf("\n");
		}
		if (current == NULL) printf("Такой записи нет\n");
		printf("\n");
	}
}

static void checkDetails(NodePtr newNode)
{
	printf("Введите количество годных деталей: ");
	scanf_s("%d", &newNode->usable);
	while (newNode->total < newNode->usable)
	{
		puts("Количество годных деталей должно быть не больше их общего количества. Введите еще раз ");
		scanf_s("%d", &newNode->usable);
	}
}
