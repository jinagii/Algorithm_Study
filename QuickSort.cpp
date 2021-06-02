#include "iostream"
#include "windows.h"

using namespace std;

void QuickSort(int, int);
int Swap(int&, int&);

const int arraySize = 25;

int* IntegerArray = new int[arraySize]; // 배열 동적 할당 선언

int main()
{
	 // 수행시간 재는 기능
	 LARGE_INTEGER Frequency;
	 LARGE_INTEGER BeginTime;
	 LARGE_INTEGER Endtime;

	 QueryPerformanceFrequency(&Frequency);

	 for (int i = 0; i < arraySize; i++)
	 {
		  IntegerArray[i] = i;
	 }

	 // 랜덤으로 숫자 섞기
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
	 cout << "자료 준비" << endl;

	 for (int i = 0; i < arraySize; i++)
	 {
		  cout << i << " : " << IntegerArray[i] << "\n";
	 }

	 cout << "정렬 시작" << endl;

	 QueryPerformanceCounter(&BeginTime);	// 시작

	 QuickSort(0, arraySize - 1);				/// Sorting 시작

	 QueryPerformanceCounter(&Endtime);		// 끝

	 cout << "정렬 끝!\n\n";

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

// Quick sort 시작 : 기준 배열을 정하고 왼쪽은 작은 수, 오른쪽은 큰수로 교환정렬, 재귀함수로 반복 정렬
void QuickSort(int left, int right)
{
	 if (left >= right)
		  return;
	 int low = left, high = right;
	 int pivot = IntegerArray[(left + right) / 2];	// 가운데를 피벗으로 설정

	 while (low <= high)
	 {
		  // 피벗보다 작을때
		  while (IntegerArray[low] < pivot)
		  {
				low++;
		  }

		  // 피벗보다 클때
		  while (IntegerArray[high] > pivot)
		  {
				high--;
		  }

		  if (low > high) break;

		  Swap(IntegerArray[low], IntegerArray[high]);

		  low++;
		  high--;
	 }

	 QuickSort(left, high);
	 QuickSort(low, right);
}

int Swap(int& a, int& b)
{
	 int temp;

	 temp = a;
	 a = b;
	 b = temp;

	 return a, b;
}