#include<stdio.h>
#include<locale.h>
#include"Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	Stack stack1, stack2;
	bool exit(false);
	const int size_first = getStackSize();
	const int size_second = getStackSize();
	initStack(&stack1, size_first);
	initStack(&stack2, size_second);
	printf("Работа со стеком\nВыберите операцию\n");
	while (!exit)
	{
		switch (menu())
		{
		case 1: push(chooseStack(&stack1, &stack2), getElement()); break;
		case 2: printf("Из какого стека хотите удалить элемент?\n");
			int choose;
			scanf_s("%d", &choose);
			switch (choose)
			{
			case 1: pop(&stack1); break;
			case 2: pop(&stack2); break;
			default: puts("Неверное значение\n"); break;
			}
			break;
		case 3: displayFirst(&stack1); break;
		case 4: displaySecond(&stack2); break;
		case 5: displayAll(&stack1, &stack2); break;
		case 6: exit = true; break;
		default: puts("Неверное значение\n"); break;
		}
	}
	return 0;
}