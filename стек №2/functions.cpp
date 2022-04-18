#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int menu()
{
	printf("1-�������� ������� � ����\n2-������� ������� �� �����\n"
		"3-������� 1 ���� �� �����\n4-������� 2 ���� �� �����\n5-������� ��� ����� �� �����\n6-����� �� ���������\n");
	int operation;
	scanf_s("%d", &operation);
	printf("\n");
	return operation;
}

int getStackSize()
{
	static int i = 1;
	printf("������e ������ %d �����\n", i);
	i++;
	int size;
	scanf_s("%d", &size);
	return size;
}

int initStack(StackPtr stack, const int size)
{
	stack->array = (char*)malloc(size);
	if (stack->array == NULL)
	{
		printf("�� ������� ������� ����\n");
		return 0;
	}
	stack->arrSize = size;
	stack->head = 0;
}

static bool isEmpty(StackPtr stack)
{
	if (stack->head == 0) return true;
	return false;
}

static bool isFull(StackPtr stack)
{
	if (stack->head == stack->arrSize) return true;
	return false;
}

StackPtr chooseStack(StackPtr first, StackPtr second)
{
	if (first->head == first->arrSize) return second;
	if (second->head == second->arrSize) return first;
	if (first->head <= second->head) return first;
	return second;
}

char getElement()
{
	printf("������� ������\n");
	char c;
	getchar();
	c = getchar();
	return c;
}

int push(StackPtr stack, char Element)
{
	if (isFull(stack))
	{
		printf("���� ��������.\n");
		return 0;
	}
	stack->array[stack->head++] = Element;
}

char pop(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("���� ����.\n");
		return 0;
	}
	stack->head--;
	return stack->array[stack->head];
}

int displayFirst(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("���� ����.\n");
		return 0;
	}
	for(int i=0; i<stack->head; i++)
	{
		printf("%c-->", stack->array[i]);
	}
	printf("\n");
}
int displaySecond(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("���� ����.\n");
		return 0;
	}
	for(int i =0; i<stack->head; i++)
	{
		printf("%c-->", stack->array[i]);
	}
	printf("\n");
}
void displayAll(StackPtr first, StackPtr second)
{
	if (isEmpty(first))	printf("���� 1 ����.\n");
	if (isEmpty(second)) printf("���� 2 ����.\n");
	printf("������ ����:\n");
	for(int i=0; i<first->head; i++)
	{
		printf("%c-->", first->array[i]);
	}
	printf("\n������ ����\n");
	for(int i=0; i<second->head; i++)
	{
		printf("%c-->", second->array[i]);
	}
	printf("\n");


}