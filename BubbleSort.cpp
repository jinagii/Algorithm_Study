#include "iostream"
#include "windows.h"

using namespace std;

void BubbleSort(int*, int);

int main()
{
	// ����ð� ������� ���
	LARGE_INTEGER Frequency;
	LARGE_INTEGER BeginTime;
	LARGE_INTEGER Endtime;

	// ������ ����
	/// cpu�κ��� tick�� �޾ƿ��°� ������ �����غ�����
	QueryPerformanceFrequency(&Frequency);

	const int arraySize = 25;

	int* IntegerArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		IntegerArray[i] = i;
	}

	// �迭�� �Ҵ�� ���� ���� (�������� ����)
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
	cout << "�ڷ� �غ� ��\n\n";

	for (int i = 0; i < arraySize; i++)
	{
		cout << i << " : " << IntegerArray[i] << "\n";
	}

	cout << "���� ����" << endl;
			
	QueryPerformanceCounter(&BeginTime);	// ����

	BubbleSort(IntegerArray, arraySize);	/// Sorting ����

	QueryPerformanceCounter(&Endtime);		// ��

	cout << "���� ��!" << endl;

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

// Bubble sort : �迭���� ���ʰ� �������� ���ؼ� �������� ������ �ٲ�
void BubbleSort(int* arr, int size)	
{
	for (int j = 0; j < size - 2; j++)
	{
		for (int i = 0; i < size - j - 1; i++)	// j�� ���� ����: ������ �ѹ����� �������ڸ��� �������� (= ���� ������ -j��)
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
