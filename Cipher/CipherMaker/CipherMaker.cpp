#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// cipher Ű 
int key = 0;

void Cipher()
{
	 cout << "Type number for Cipher key : ";
	 cin >> key;

	 // map�� ����� ����
	 map<char, char> CipherTable;	// ���ĺ��� ������ ������ ����
	 map<char, char>::iterator iter;

	 // for������ ���ĺ��� map�� first�� �ʱ�ȭ
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

	 // ���̺� ���
	 for (iter = CipherTable.begin(); iter != CipherTable.end(); iter++)
	 {
		  cout << iter->first << " -> " << iter->second << endl;
	 }

	 cout << endl;
	 //cout << "----------Character Counting----------" << endl;

	 // �ҷ��� text ���� 
	 ifstream _readfile;
	 _readfile.open("Test_Read.txt");

	 string str;	// �ҷ��� ���� ���� ����

	 cout << "----------Origianl Text----------" << endl;

	 // ������ �ҷ����� str�� ����
	 if (_readfile.is_open() == true)
	 {
		  while (getline(_readfile, str))
		  {
				// Origianl �ؽ�Ʈ ���
				cout << str << endl;
		  }

		  _readfile.close();
	 }
	 else
	 {
		  cout << "file open fail" << endl;
	 }

	 // ��ȣȭ 
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

	 // ��ȣȭ ���� ���� ����
	 ofstream _cipherText;
	 _cipherText.open("Test_Cipher.txt");
	 _cipherText.write(str.c_str(), str.size());

	 cout << endl;
	 cout << "----------Cipher Text----------" << endl;

	 // ��ȣȭ �ؽ�Ʈ ���
	 cout << str << endl;

	 // ��ȣȭ 
	 cout << endl;
	 cout << "----------Decryption----------" << endl;

	 // ��ȣȭ �ؽ�Ʈ ���� ����
	 ofstream _DecryptionText;
	 string strCipher;
	 strCipher = str;

	 // ��ȣȭ for ��
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

	 // ��ȣȭ�� ��ȣȭ ��
	 strCipher = str + '\n' + strCipher;

	 cout << strCipher << endl;

	 // ����� ����
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