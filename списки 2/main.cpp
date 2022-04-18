#include<stdio.h>
#include<locale.h>
#include"header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	NodePtr root = NULL;

	printf("Работа со списком структур\nВыберите опреацию:\n");
	while (true)
	{
		switch (menu())
		{
		case 1: input(&root); break;
		case 2: deleteData(&root); break;
		case 3: output(root); break;
		case 4: output_certain_data(root); break;
		case 5: sort(root); break;
		}
	}
}