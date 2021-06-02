#include "iostream"
#include "windows.h"

using namespace std;

void BubbleSort(int*, int);

int main()
{
	// 수행시간 재기위한 기능
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;

	// 교수님 제공
	/// cpu로부터 tick을 받아오는거 같은데 공부해봐야함
	QueryPerformanceFrequency(&Frequency);

	const int arraySize = 25;

	int* IntegerArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		IntegerArray[i] = i;
	}

	// 배열에 할당된 숫자 섞기 (랜덤으로 섞음)
	for (int i = 0; i < arraySize * 2; i++)		
	{
		int index1 = rand() % arraySize;
		int index2 = rand() % arraySize;
		int temp = 0;

		temp = IntegerArray[index1];
		IntegerArray[index1] = IntegerArray[index2];
		IntegerArray[index2] = temp;
	}

	/// 자료 준비 
	cout << "자료 준비 끝\n\n";

	for (int i = 0; i < arraySize; i++)
	{
		cout << i << " : " << IntegerArray[i] << "\n";
	}

	cout << "정렬 시작" << endl;
			
	QueryPerformanceCounter(&BeginTime);	// 시작

	BubbleSort(IntegerArray, arraySize);	/// Sorting 시작

	QueryPerformanceCounter(&Endtime);		// 끝

	cout << "정렬 끝!" << endl;

	for (int i = 0; i < arraySize; i++)
	{
		cout << i << " : " << IntegerArray[i] << "\n";
	}

	__int64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	double duringtime = (double)elapsed / (double)Frequency.QuadPart;

	cout << "수행시간 : " << fixed << duringtime;

	delete[] IntegerArray;

	return 0;
}

// Bubble sort : 배열에서 왼쪽과 오른쪽을 비교해서 오른쪽이 작으면 바꿈
void BubbleSort(int* arr, int size)	
{
	for (int j = 0; j < size - 2; j++)
	{
		for (int i = 0; i < size - j - 1; i++)	// j를 빼는 이유: 루프를 한번돌면 마지막자리는 정해진다 (= 다음 루프는 -j번)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}
