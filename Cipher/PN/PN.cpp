#include <iostream>
#include <string>
#include <random>
#include <tchar.h>

using namespace std;

int main()
{
	string str;

	// random ���� ���� ����
	string randpn;
	random_device rand;
	mt19937 generate(rand());
	uniform_int_distribution<int> dist(0, 9);

	//srand()
	cout << "Type text to PN:";
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		//randpn = pow(10, i);
		randpn.push_back(dist(generate));
	}

	//randpn.format
	for (int i = 0; i < str.size(); i++)
	{
		cout << (int)randpn[i] ;
	}

	cout << endl;
	cout << "----------PN Encryption----------";
	cout << endl;

	string pnMessage;
	pnMessage = str; // pn�޼��� �ʱ�ȭ

	// ������ randpn ���ϱ�
	for (int i = 0; i < str.size(); i++)
	{
		pnMessage[i] = (int)str[i] + (int)randpn[i];
	}

	// pn �޼��� ���
	for (int i = 0; i < str.size(); i++)
	{
		cout << (int)pnMessage[i];
	}

	cout << endl;
	cout << "----------PN Decryption----------";
	cout << endl;

	// pn ��ȣȭ 
	string backtoOrigin;
	backtoOrigin = pnMessage; // pn��ȣȭ �޼��� �ʱ�ȭ

	// �������� ���� randpn ����
	for (int i = 0; i < str.size(); i++)
	{
		backtoOrigin[i] = (int)pnMessage[i] - (int)randpn[i];
	}

	cout << backtoOrigin;

	return 0;
}