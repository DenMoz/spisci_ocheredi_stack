#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int menu()
{
	printf("1-�������� ������� � ����\n2-������� ������� �� �����\n"
		"3-������� 1 ���� �� �����\n4-������� 2 ���� �� �����\n5-������� ��� ����� �� �����\n6-����� �� ���������");
	int operation;
	scanf_s("%d", &operation);
	printf("\n");
	return operation;
}

int getStackSize()
{
	printf("������ ������ �����\n");
	int size;
	scanf_s("%d", &size);
	return size;
}

void initStack(StackPtr stack, const int size)
{
	stack->array = (char*)malloc(size);
	if (stack->array == NULL)
	{
		printf("�� ������� ������� ����\n");
		exit(1);
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

void push(StackPtr stack, char Element)
{
	stack->array[stack->head++] = Element;
}

char pop(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("���� ����.\n");
		exit(1);
	}
	return stack->array[--stack->head];
}

void displayFirst(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("���� ����.\n");
		exit(1);
	}
	while (stack->head != stack->arrSize)
	{
		printf("%c-->", stack->array[stack->head]);
		stack->head++;
	}
}
void displaySecond(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("���� ����.\n");
		exit(1);
	}
	while (stack->head != stack->arrSize)
	{
		printf("%c-->", stack->array[stack->head]);
		stack->head++;
	}
}
void displayAll(StackPtr first, StackPtr second)
{
	if (isEmpty(first))	printf("���� 1 ����.\n");
	if (isEmpty(second)) printf("���� 2 ����.\n");
	printf("������ ����:\n");
	while (first->head != first->arrSize)
	{
		printf("%c-->", first->array[first->head]);
		first->head++;
	}
	printf("\n������ ����\n");
	while (second->head != second->arrSize)
	{
		printf("%c-->", second->array[second->head]);
		second->head++;
	}
	printf("\n");


}