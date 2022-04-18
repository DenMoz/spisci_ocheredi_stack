#include<stdio.h>
#include"header.h"
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	NodePtr root = NULL;
	int number, kol;
	int(*FuncPtr)() = getNumber;
	printf("Работа со списками\nВыберите операцию\n");
	while (true)
	{
		switch (menu())
		{
		case 1: input(&root, FuncPtr);
			printList(root);
			break;
		case 2: printf("Количество элементов списка равно %d", countList(&root));
			break;
		case 3: printList(root);
			break;
		case 4: findMax(&root);
			break;
		case 5: findMin(&root);
			break;
		case 6: deleteRep(root);
			printList(root);
			break;
		case 7:
			kol=countList(&root);
			printf("Введите число, которое необходимо удалить\n");
			int num;
			scanf_s("%d", &num);
			deleteAll(&root, num, kol);
			break;
		case 8: sort(&root);
			printList(root);
			break;
		case 0: return 0; break;
		default: puts("Неверное значение\n"); break;
		}
	}
	return 0;

}