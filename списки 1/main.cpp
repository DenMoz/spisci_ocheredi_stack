#include<stdio.h>
#include"header.h"
#include<locale.h>
int main()
{
	setlocale(LC_ALL, "rus");
	NodePtr root = NULL;
	int number, kol;
	int(*FuncPtr)() = getNumber;
	printf("������ �� ��������\n�������� ��������\n");
	while (true)
	{
		switch (menu())
		{
		case 1: input(&root, FuncPtr);
			printList(root);
			break;
		case 2: printf("���������� ��������� ������ ����� %d", countList(&root));
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
			printf("������� �����, ������� ���������� �������\n");
			int num;
			scanf_s("%d", &num);
			deleteAll(&root, num, kol);
			break;
		case 8: sort(&root);
			printList(root);
			break;
		case 0: return 0; break;
		default: puts("�������� ��������\n"); break;
		}
	}
	return 0;

}