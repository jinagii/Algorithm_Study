#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <vector>

using namespace std;

vector<int> primeNumbers;	// 소수 저장소

int p, q;		// p, q값 선언
int* pp = &p;
int* pq = &q;

int N;
int Phi_N;

int e;
int d = 1;

void GetPrimeNumber();
void GetRandomPQ();

int Get_N(int* p, int* q);
int Get_Phi_N(int* p, int* q);
int Find_e(int Phi_N);
int Find_d(int e, int Phi_N);


int main()
{
	srand(time(NULL));

	GetPrimeNumber();

	GetRandomPQ();

	cout << "p :     " << p << endl;
	cout << "q :     " << q << endl;


	N = Get_N(pp, pq);
	cout << "N :     " << N << endl;

	Phi_N = Get_Phi_N(pp, pq);
	cout << "Phi_N : " << Phi_N << endl;

	e = Find_e(Phi_N);
	cout << "e :     " << e << endl;

	d = Find_d(e, Phi_N);
	cout << "d :     " << d << endl;

	cout << "------------------------------------------" << endl;

	cout << "Open Key (N, e) : " << "( "<< N << ", "<< e <<" )"<< endl;
	cout << "Private Key (N, d) : " << "( "<< N << ", "<< d <<" )"<< endl;

	cout << "------------------------------------------" << endl;

	long M = 533%N;
	cout << "Original message M from A : " << M << endl;

	unsigned long c = ((unsigned long)pow(M, e) % N);
	cout << "Encrytion code c : " << c << endl;

	cout << "------------------------------------------" << endl;

	cout << "Decryption code c by B" << endl;

	unsigned long M2 = ((unsigned long)pow(c, d) % N);
	cout << "Original message : " << M2 <<endl;
}


void GetPrimeNumber()
{
	map<int, bool> checkPrimeNumber;	// 소수 체크할 맵
	map<int, bool> ::iterator iter;

	for (int i = 2; i < 15; i++)
	{
		checkPrimeNumber.insert(pair<int, bool>(i, true));
	}

	for (iter = checkPrimeNumber.begin(); iter != checkPrimeNumber.end(); iter++)
	{
		for (int i = 2; i < iter->first; i++)
		{
			if (iter->first % i == 0)
			{
				iter->second = false;
				break;
			}
		}
	}

	for (iter = checkPrimeNumber.begin(); iter != checkPrimeNumber.end(); iter++)
	{
		if (iter->second == true)
		{
			cout << iter->first << endl;	// 소수 확인하고 소수 넣기 ~50까지
			primeNumbers.push_back(iter->first);
		}
	}
}

void GetRandomPQ()
{
	int pIndex;
	int qIndex;

	do
	{
		pIndex = rand() % primeNumbers.size();
		qIndex = rand() % primeNumbers.size();
	} while (pIndex == qIndex);

	*pp = primeNumbers[pIndex];
	*pq = primeNumbers[qIndex];
}


int Get_N(int* p, int* q)
{
	int N = (*p) * (*q);

	return N;
}

int Get_Phi_N(int* p, int* q)
{
	int Phi_N = ((*p) - 1) * ((*q) - 1);

	return Phi_N;
}

int Find_e(int Phi_N)
{
	int temp=1;

	for (int i = 2; i < Phi_N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0 && Phi_N % j == 0)
			{
				temp = j;
			}
		}

		if (temp == 1)
		{
			e = i;
			break;
		}
		temp = 1;
	}

	return e;
}

int Find_d(int e, int Phi_N)
{
	while (1)
	{
		d++;
		if ((d * e) % Phi_N == 1)
		{
			return d;
		}
	}
}

