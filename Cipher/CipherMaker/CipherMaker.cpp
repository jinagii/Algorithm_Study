#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// cipher 키 
int key = 0;

void Cipher()
{
	 cout << "Type number for Cipher key : ";
	 cin >> key;

	 // map을 사용해 봤음
	 map<char, char> CipherTable;	// 알파벳과 갯수를 쌍으로 저장
	 map<char, char>::iterator iter;

	 // for문으로 알파벳을 map의 first에 초기화
	 for (int i = 0; i < 26; i++)
	 {
		  char Alphabet = 'a' + i;
		  int C_Key = i + key;

		  if ((C_Key) >= 26)
		  {
				C_Key = C_Key % 26;
		  }
		  char CipherAlphabet = 'a' + C_Key;

		  CipherTable.insert(pair<char, char>(Alphabet, CipherAlphabet));
	 }

	 // 테이블 출력
	 for (iter = CipherTable.begin(); iter != CipherTable.end(); iter++)
	 {
		  cout << iter->first << " -> " << iter->second << endl;
	 }

	 cout << endl;
	 //cout << "----------Character Counting----------" << endl;

	 // 불러올 text 파일 
	 ifstream _readfile;
	 _readfile.open("Test_Read.txt");

	 string str;	// 불러온 파일 문자 저장

	 cout << "----------Origianl Text----------" << endl;

	 // 파일을 불러오고 str에 저장
	 if (_readfile.is_open() == true)
	 {
		  while (getline(_readfile, str))
		  {
				// Origianl 텍스트 출력
				cout << str << endl;
		  }

		  _readfile.close();
	 }
	 else
	 {
		  cout << "file open fail" << endl;
	 }

	 // 암호화 
	 for (int i = 0; i < str.size(); i++)
	 {
		  for (iter = CipherTable.begin(); iter != CipherTable.end(); iter++)
		  {
				if (str[i] == iter->first)
				{
					 str[i] = iter->second;
					 break;
				}
		  }
	 }

	 // 암호화 파일 저장 변수
	 ofstream _cipherText;
	 _cipherText.open("Test_Cipher.txt");
	 _cipherText.write(str.c_str(), str.size());

	 cout << endl;
	 cout << "----------Cipher Text----------" << endl;

	 // 암호화 텍스트 출력
	 cout << str << endl;

	 // 복호화 
	 cout << endl;
	 cout << "----------Decryption----------" << endl;

	 // 복호화 텍스트 저장 변수
	 ofstream _DecryptionText;
	 string strCipher;
	 strCipher = str;

	 // 복호화 for 문
	 for (int i = 0; i < strCipher.size(); i++)
	 {
		  for (iter = CipherTable.begin(); iter != CipherTable.end(); iter++)
		  {
				if (strCipher[i] == iter->second)
				{
					 strCipher[i] = iter->first;
					 break;
				}
		  }
	 }

	 // 복호화와 암호화 비교
	 strCipher = str + '\n' + strCipher;

	 cout << strCipher << endl;

	 // 결과문 저장
	 _DecryptionText.open("Test_Decryption.txt");
	 _DecryptionText.write(strCipher.c_str(), strCipher.size());

	 _cipherText.close();
	 _DecryptionText.close();
}

int main()
{
	 Cipher();

	 return 0;
}