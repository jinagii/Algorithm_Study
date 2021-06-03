#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>

using namespace std;

// 기존의 시간시드 난수 뽑기
void RandomNumberFromTimeSeed();
// 다른방법 생각해보기
void RandomNumberFromAnotherMethod();

int main()
{
	// 기존 난수 뽑기
	RandomNumberFromTimeSeed();

	// 다른 방법의 랜덤 숫자 함수 (mt19937)
	RandomNumberFromAnotherMethod();
}

/// 시간에 따른 랜덤 시드 
/// 난수처럼 보이나 실제로는 무작위가 아닌 의사난수를 생성
/// time()은 어떤 시간 이후 초수를 반환하는 함수 - 시드가 천천히 변함
void RandomNumberFromTimeSeed()
{
	srand(time(NULL));

	int randomNumber = rand() % 9999;

	cout << "random number : " << randomNumber << endl;
	cout << "random number : " << randomNumber << endl;
}

/// random 라이브러리를 사용
/// 운영체제 단에서 제공하는 난수를 이용 
/// mt19937은 난수생성 엔진 중 하나, 메르센트위스터 
/// 분포를 선언하고 뽑는다
void RandomNumberFromAnotherMethod()
{
	random_device rand;

	mt19937 generate(rand());

	uniform_int_distribution<int> dist(0, 9999);

	cout << "random number : " << dist(generate) << endl;
	cout << "random number : " << dist(generate) << endl;
}

