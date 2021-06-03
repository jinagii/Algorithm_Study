#include <iostream>
#include <string>
#include <random>
#include <tchar.h>

using namespace std;

int main()
{
	string str;

	// random 숫자 변수 생성
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
	pnMessage = str; // pn메세지 초기화

	// 원본에 randpn 더하기
	for (int i = 0; i < str.size(); i++)
	{
		pnMessage[i] = (int)str[i] + (int)randpn[i];
	}

	// pn 메세지 출력
	for (int i = 0; i < str.size(); i++)
	{
		cout << (int)pnMessage[i];
	}

	cout << endl;
	cout << "----------PN Decryption----------";
	cout << endl;

	// pn 복호화 
	string backtoOrigin;
	backtoOrigin = pnMessage; // pn복호화 메세지 초기화

	// 원본으로 복귀 randpn 빼기
	for (int i = 0; i < str.size(); i++)
	{
		backtoOrigin[i] = (int)pnMessage[i] - (int)randpn[i];
	}

	cout << backtoOrigin;

	return 0;
}