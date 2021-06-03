#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// �ؽ�Ʈ ������ ���ڸ� �б� ���� �Լ�
// ���� �� ���ĺ� ���� ������ Ȯ��
void ReadandWriteText()
{
	// �ҷ��� ���� 
	ifstream _readfile;
	_readfile.open("Test_Read.txt");

	string str;	// �ҷ��� ���� ���� ����

	cout << "----------Cipher Text----------" << endl;

	// ������ �ҷ����� str�� ����
	if (_readfile.is_open() == true)
	{
		while (getline(_readfile, str))
		{
			// Cipher �ؽ�Ʈ ���
			cout << str << endl;
		}

		_readfile.close();
	}
	else
	{
		cout << "file open fail" << endl;
	}
	//cout << str.size() << endl;

	// map�� ����� ����
	map<int, char> countChar;	// ���ĺ��� ������ ������ ����
	map<int, char>::iterator iter;

	// for������ ���ĺ��� map�� first�� �ʱ�ȭ
	for (int i = 0; i < 26; i++)
	{
		char Alphabet = 'a' + i;

		countChar.insert(pair<char, int>(Alphabet, 0));
	}

	// str�� first�� ���Ͽ� ������ ���� ����
	for (int i = 0; i < str.size(); i++)
	{
		for (iter = countChar.begin(); iter != countChar.end(); iter++)
		{
			if (str[i] == iter->first)
			{
				iter->second++;

				break;
			}
		}
	}

	cout << endl;
	cout << "----------Character Counting----------" << endl;

	// ���ĺ��� ��� ���ƴ��� ���
	for (iter = countChar.begin(); iter != countChar.end(); iter++)
	{
		cout << (char)iter->first << " : " << (int)iter->second << endl;
	}

	// �ʿ� �־��
	map<char, char> CipherTable;
	map<char, char>::iterator iterCi;
	CipherTable.insert(pair<char, char>('a', 'C'));
	CipherTable.insert(pair<char, char>('b', 'F'));
	CipherTable.insert(pair<char, char>('c', 'I'));
	CipherTable.insert(pair<char, char>('d', 'E'));
	CipherTable.insert(pair<char, char>('e', 'S'));
	CipherTable.insert(pair<char, char>('f', 'U'));
	CipherTable.insert(pair<char, char>('g', 'P'));
	CipherTable.insert(pair<char, char>('h', 'Y'));
	CipherTable.insert(pair<char, char>('i', 'R'));
	CipherTable.insert(pair<char, char>('j', 'X'));
	CipherTable.insert(pair<char, char>('k', 'M'));
	CipherTable.insert(pair<char, char>('l', 'A'));
	CipherTable.insert(pair<char, char>('m', 'O'));
	CipherTable.insert(pair<char, char>('n', 'J'));
	CipherTable.insert(pair<char, char>('o', 'K'));
	CipherTable.insert(pair<char, char>('p', 'G'));
	CipherTable.insert(pair<char, char>('q', '-'));
	CipherTable.insert(pair<char, char>('r', 'W'));
	CipherTable.insert(pair<char, char>('s', 'N'));
	CipherTable.insert(pair<char, char>('t', 'B'));
	CipherTable.insert(pair<char, char>('u', '-'));
	CipherTable.insert(pair<char, char>('v', 'T'));
	CipherTable.insert(pair<char, char>('w', 'D'));
	CipherTable.insert(pair<char, char>('x', 'L'));
	CipherTable.insert(pair<char, char>('y', 'H'));
	CipherTable.insert(pair<char, char>('z', 'V'));

	for (int i = 0; i < str.size(); i++)
	{
		for (iterCi = CipherTable.begin(); iterCi != CipherTable.end(); iterCi++)
		{
			if (str[i] == iterCi->first)
			{
				str[i] = iterCi->second;
				break;
			}
		}
	}

	// ���� ����
	ofstream _writeText;
	_writeText.open("Test_Write.txt");
	_writeText.write(str.c_str(), str.size());

	_writeText.close();

	cout << endl;
	cout << "----------Origianl Song Lyric----------" << endl;

	cout << str << endl;
}

int main()
{
	ReadandWriteText();

	return 0;
}