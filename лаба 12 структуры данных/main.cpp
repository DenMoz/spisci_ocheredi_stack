#include<stdio.h>
#include"header.h"
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	NodePtr root=NULL;
	int number;
	int(*FuncPtr)() = getNumber;
	printf("Работа со списками\nВыберите операцию\n");
	while (true)
	{
		switch (menu())
		{
		case 1: input(&root, FuncPtr);
			break;
		case 2: printf("Количество элементов списка равно %d", countList(&root));
			break;
		case 3: printList(root);
			break;
		case 4: findMax(&root);
			break;
		case 5: findMin(&root);
			break;
		case 6: deleteRep(&root);
			break;
		}
	}
	return 0;

}