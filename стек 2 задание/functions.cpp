#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int menu()
{
	printf("1-Добавить элемент в стек\n2-Удалить элемент из стека\n"
		"3-Вывести 1 стек на экран\n4-Вывести 2 стек на экран\n5-Вывести оба стека на экран\n6-Выход из программы");
	int operation;
	scanf_s("%d", &operation);
	printf("\n");
	return operation;
}

int getStackSize()
{
	printf("Введит размер стека\n");
	int size;
	scanf_s("%d", &size);
	return size;
}

void initStack(StackPtr stack, const int size)
{
	stack->array = (char*)malloc(size);
	if (stack->array == NULL)
	{
		printf("Не удалось создать стек\n");
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
	printf("Введите символ\n");
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
		printf("Стек пуст.\n");
		exit(1);
	}
	return stack->array[--stack->head];
}

void displayFirst(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("Стек пуст.\n");
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
		printf("Стек пуст.\n");
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
	if (isEmpty(first))	printf("Стек 1 пуст.\n");
	if (isEmpty(second)) printf("Стек 2 пуст.\n");
	printf("Первый стек:\n");
	while (first->head != first->arrSize)
	{
		printf("%c-->", first->array[first->head]);
		first->head++;
	}
	printf("\nВторой стек\n");
	while (second->head != second->arrSize)
	{
		printf("%c-->", second->array[second->head]);
		second->head++;
	}
	printf("\n");


}