#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// 텍스트 파일의 문자를 읽기 위한 함수
// 읽은 뒤 알파벳 별로 갯수를 확인
void ReadandWriteText()
{
	// 불러올 파일 
	ifstream _readfile;
	_readfile.open("Test_Read.txt");

	string str;	// 불러온 파일 문자 저장

	cout << "----------Cipher Text----------" << endl;

	// 파일을 불러오고 str에 저장
	if (_readfile.is_open() == true)
	{
		while (getline(_readfile, str))
		{
			// Cipher 텍스트 출력
			cout << str << endl;
		}

		_readfile.close();
	}
	else
	{
		cout << "file open fail" << endl;
	}
	//cout << str.size() << endl;

	// map을 사용해 봤음
	map<int, char> countChar;	// 알파벳과 갯수를 쌍으로 저장
	map<int, char>::iterator iter;

	// for문으로 알파벳을 map의 first에 초기화
	for (int i = 0; i < 26; i++)
	{
		char Alphabet = 'a' + i;

		countChar.insert(pair<char, int>(Alphabet, 0));
	}

	// str과 first를 비교하여 같으면 갯수 증가
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

	// 알파벳당 몇번 사용됐는지 출력
	for (iter = countChar.begin(); iter != countChar.end(); iter++)
	{
		cout << (char)iter->first << " : " << (int)iter->second << endl;
	}

	// 맵에 넣어둠
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

	// 파일 저장
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