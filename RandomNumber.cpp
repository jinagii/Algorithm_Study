#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>

using namespace std;

// ������ �ð��õ� ���� �̱�
void RandomNumberFromTimeSeed();
// �ٸ���� �����غ���
void RandomNumberFromAnotherMethod();

int main()
{
	// ���� ���� �̱�
	RandomNumberFromTimeSeed();

	// �ٸ� ����� ���� ���� �Լ� (mt19937)
	RandomNumberFromAnotherMethod();
}

/// �ð��� ���� ���� �õ� 
/// ����ó�� ���̳� �����δ� �������� �ƴ� �ǻ糭���� ����
/// time()�� � �ð� ���� �ʼ��� ��ȯ�ϴ� �Լ� - �õ尡 õõ�� ����
void RandomNumberFromTimeSeed()
{
	srand(time(NULL));

	int randomNumber = rand() % 9999;

	cout << "random number : " << randomNumber << endl;
	cout << "random number : " << randomNumber << endl;
}

/// random ���̺귯���� ���
/// �ü�� �ܿ��� �����ϴ� ������ �̿� 
/// mt19937�� �������� ���� �� �ϳ�, �޸���Ʈ������ 
/// ������ �����ϰ� �̴´�
void RandomNumberFromAnotherMethod()
{
	random_device rand;

	mt19937 generate(rand());

	uniform_int_distribution<int> dist(0, 9999);

	cout << "random number : " << dist(generate) << endl;
	cout << "random number : " << dist(generate) << endl;
}

