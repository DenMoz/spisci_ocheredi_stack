#include<stdio.h>
#include<stdlib.h>
#include"Header.h"

int menu()
{
	printf("1-Добавить элемент в стек\n2-Удалить элемент из стека\n"
		"3-Вывести 1 стек на экран\n4-Вывести 2 стек на экран\n5-Вывести оба стека на экран\n6-Выход из программы\n");
	int operation;
	scanf_s("%d", &operation);
	printf("\n");
	return operation;
}

int getStackSize()
{
	static int i = 1;
	printf("Введитe размер %d стека\n", i);
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
		printf("Не удалось создать стек\n");
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
	printf("Введите символ\n");
	char c;
	getchar();
	c = getchar();
	return c;
}

int push(StackPtr stack, char Element)
{
	if (isFull(stack))
	{
		printf("Стек заполнен.\n");
		return 0;
	}
	stack->array[stack->head++] = Element;
}

char pop(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("Стек пуст.\n");
		return 0;
	}
	stack->head--;
	return stack->array[stack->head];
}

int displayFirst(StackPtr stack)
{
	if (isEmpty(stack))
	{
		printf("Стек пуст.\n");
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
		printf("Стек пуст.\n");
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
	if (isEmpty(first))	printf("Стек 1 пуст.\n");
	if (isEmpty(second)) printf("Стек 2 пуст.\n");
	printf("Первый стек:\n");
	for(int i=0; i<first->head; i++)
	{
		printf("%c-->", first->array[i]);
	}
	printf("\nВторой стек\n");
	for(int i=0; i<second->head; i++)
	{
		printf("%c-->", second->array[i]);
	}
	printf("\n");


}