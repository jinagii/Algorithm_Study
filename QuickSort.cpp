#include "iostream"
#include "windows.h"

using namespace std;

void QuickSort(int, int);
int Swap(int&, int&);

const int arraySize = 25;

int* IntegerArray = new int[arraySize]; // �迭 ���� �Ҵ� ����

int main()
{
	 // ����ð� ��� ���
	 LARGE_INTEGER Frequency;
	 LARGE_INTEGER BeginTime;
	 LARGE_INTEGER Endtime;

	 QueryPerformanceFrequency(&Frequency);

	 for (int i = 0; i < arraySize; i++)
	 {
		  IntegerArray[i] = i;
	 }

	 // �������� ���� ����
	 for (int i = 0; i < arraySize * 2; i++)
	 {
		  int index1 = rand() % arraySize;
		  int index2 = rand() % arraySize;
		  int temp = 0;

		  temp = IntegerArray[index1];
		  IntegerArray[index1] = IntegerArray[index2];
		  IntegerArray[index2] = temp;
	 }

	 /// �ڷ� �غ�
	 cout << "�ڷ� �غ�" << endl;

	 for (int i = 0; i < arraySize; i++)
	 {
		  cout << i << " : " << IntegerArray[i] << "\n";
	 }

	 cout << "���� ����" << endl;

	 QueryPerformanceCounter(&BeginTime);	// ����

	 QuickSort(0, arraySize - 1);				/// Sorting ����

	 QueryPerformanceCounter(&Endtime);		// ��

	 cout << "���� ��!\n\n";

	 for (int i = 0; i < arraySize; i++)
	 {
		  cout << i << " : " << IntegerArray[i] << "\n";
	 }

	 __int64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
	 double duringtime = (double)elapsed / (double)Frequency.QuadPart;

	 cout << "����ð� : " << fixed << duringtime;

	 delete[] IntegerArray;

	 return 0;
}

// Quick sort ���� : ���� �迭�� ���ϰ� ������ ���� ��, �������� ū���� ��ȯ����, ����Լ��� �ݺ� ����
void QuickSort(int left, int right)
{
	 if (left >= right)
		  return;
	 int low = left, high = right;
	 int pivot = IntegerArray[(left + right) / 2];	// ����� �ǹ����� ����

	 while (low <= high)
	 {
		  // �ǹ����� ������
		  while (IntegerArray[low] < pivot)
		  {
				low++;
		  }

		  // �ǹ����� Ŭ��
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