#include "stdio.h"

int main()
{
	 char SuperrrStack[10] = { 0, };   // ���� �迭 ũ�� 10
	 int SuperIndex = 0;         // �迭�� �ε��� 
	 char inputchar;      // ���ÿ� ���� ��
	 int inputMenu;

	 while (true)
	 {
		  printf("\n 1. Push / 2. Pop \n\n");

		  scanf_s("%d", &inputMenu);
		  printf("Number : %d\n", inputMenu);

		  if (inputMenu == 1)
		  {
				if (SuperIndex == 10)
				{
					 printf("Array is full.\n");

				}
				else
				{
					 printf("Push is chosen, type character\n");
					 rewind(stdin);
					 scanf_s("%c", &inputchar, 1);

					 printf("Typed : %c \n", inputchar);

					 //������ ���ÿ� ������ �ִ´�.
					 SuperStack[SuperIndex] = inputchar;
					 SuperIndex++;
				}
		  }
		  else if (inputMenu == 2)
		  {
				if (SuperIndex == 0)
				{
					 printf("Array is empty.\n");

				}
				else
				{
					 printf("Pop is chosen. \n");
					 char result = SuperStack[SuperIndex - 1] = 0;

					 printf("Popped : %c \n", result);

					 SuperIndex--;
				}
		  }

		  printf("Stack : \n");

		  for (int InputIndex = 0; InputIndex < 10; InputIndex++)
		  {
				printf("%c ", SuperStack[InputIndex]);
		  }
	 }
}