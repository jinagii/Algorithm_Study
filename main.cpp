#include "stdio.h"
#include"string.h"

int main()
{
	 char Queue[10] = { 0, };	// �迭 ����
	 int Index = 0;				// �迭 �ε���
	 char Inputchar;				// ���� ����
	 int InputMenu;				// �޴� 

	 while (true)
	 {
		  printf("\n (1) Push / (2) Pop \n");		// pop �� push �޴� ����
		  scanf_s("%d", &InputMenu);
		  printf("Typed : %d \n", InputMenu);

		  if (InputMenu == 1)						// push ����
		  {
				if (Index == 10)
				{
					 printf("Array is full.\n");		// �迭�� ����
				}
				else
				{
					 printf("Push is chosen, type character\n");	// push �϶� 
					 rewind(stdin);
					 scanf_s("%c", &Inputchar, 1);

					 printf("Typed : %c \n", Inputchar);

					 Queue[Index] = Inputchar;			// �迭�� ���� �Է�
					 Index++;							// push �ε��� ����
				}
		  }
		  else if (InputMenu == 2)					// pop ����
		  {
				if (Index == 0)
				{
					 printf("Array is empty.\n");		// �迭�� ��
				}
				else
				{
					 printf("Pop is chosen.\n");			// pop �϶�

					 printf("Pop character : %c \n", Queue[0]);	// �׻� ���� ���ڸ� pop�Ѵ�
					 Queue[0] = 0;

					 /// ó�� �ڵ��� ��� ��� ���𸣰� ��� memmove,
					 /// �޸� �ּҸ� �ű�°����� queue�� ���� �ʴ� ���߿� �ٽ� ����� ���߰ڴ�
					 memmove(Queue - 1, Queue, sizeof(int) * 9);	// �ε����� ������ ����
					 Queue[9] = 0;
					 Index--;									// �ε��� ����
				}
		  }

		  for (int Index = 0; Index < 10; Index++)
		  {
				printf("%c ", Queue[Index]);					// �迭 ����Ʈ

		  }
		  printf("Current index: %d", Index);				// ���� push�ε��� ��ġ
	 }
}