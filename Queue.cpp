#include "stdio.h"
#include"string.h"

int main()
{
	 char Queue[10] = { 0, };	// 배열 선언
	 int Index = 0;				// 배열 인덱스
	 char Inputchar;				// 넣을 문자
	 int InputMenu;				// 메뉴 

	 while (true)
	 {
		  printf("\n (1) Push / (2) Pop \n");		// pop 과 push 메뉴 선택
		  scanf_s("%d", &InputMenu);
		  printf("Typed : %d \n", InputMenu);

		  if (InputMenu == 1)						// push 선택
		  {
				if (Index == 10)
				{
					 printf("Array is full.\n");		// 배열이 꽉참
				}
				else
				{
					 printf("Push is chosen, type character\n");	// push 일때 
					 rewind(stdin);
					 scanf_s("%c", &Inputchar, 1);

					 printf("Typed : %c \n", Inputchar);

					 Queue[Index] = Inputchar;			// 배열에 문자 입력
					 Index++;							// push 인덱스 증가
				}
		  }
		  else if (InputMenu == 2)					// pop 선택
		  {
				if (Index == 0)
				{
					 printf("Array is empty.\n");		// 배열이 빔
				}
				else
				{
					 printf("Pop is chosen.\n");			// pop 일때

					 printf("Pop character : %c \n", Queue[0]);	// 항상 앞의 문자를 pop한다
					 Queue[0] = 0;

					 /// 처음 코딩을 배울 당시 뭣모르고 썼던 memmove,
					 /// 메모리 주소를 옮기는것으로 queue에 맞지 않다 나중에 다시 만들어 봐야겠다
					 memmove(Queue - 1, Queue, sizeof(int) * 9);	// 인덱스를 앞으로 당긴다
					 Queue[9] = 0;
					 Index--;									// 인덱스 감소
				}
		  }

		  for (int Index = 0; Index < 10; Index++)
		  {
				printf("%c ", Queue[Index]);					// 배열 프린트

		  }
		  printf("Current index: %d", Index);				// 현재 push인덱스 위치
	 }
}
