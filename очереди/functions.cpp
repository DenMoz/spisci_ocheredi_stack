#include<stdio.h>
#include<stdlib.h>
#include"Header.h"
NodePtr head = NULL;
NodePtr tail = NULL;
extern int menu()
{
	printf("1-Добавить запись\n2-Удалить запись\n3-выйти из программы\n");
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
	printf("Введите наименование заказа\n");
	getchar();
	gets_s(newNode->name);
	printf("Введите полное количество деталей\n");
	scanf_s("%d", &newNode->total);
	printf("Введите количество годных деталей\n");
	scanf_s("%d", &newNode->usable);
	const static int percent(100);
	newNode->percentage = (static_cast<double>(newNode->usable) / newNode->total) * percent;
	printf("Процент годных деталей равен %lf\n", newNode->percentage);
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
		printf("Очередь пуста.\n");
	else
	{
		printf("\n");
		printf("№   Название  Общее кол-во  Кол-во годных  Процент годных\n");
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