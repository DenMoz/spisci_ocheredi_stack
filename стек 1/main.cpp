#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include"Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	printf("Работа со стеком\nВыберите операцию\n");
	while (true)
	{
		display();
		switch (menu())
		{
		case 1: push(); break;
		case 2: pop(); break;
		case 3: return 0; break;
		default: puts("Неверное значение\n"); break;
		}
	}
	return 0;
}