/*
문제
상근이의 동생 상수는 수학을 정말 못한다. 상수는 숫자를 읽는데 문제가 있다. 이렇게 수학을 못하는 상수를 위해서 상근이는 수의 크기를 비교하는 문제를 내주었다. 상근이는 세 자리 수 두 개를 칠판에 써주었다. 그 다음에 크기가 큰 수를 말해보라고 했다.

상수는 수를 다른 사람과 다르게 거꾸로 읽는다. 예를 들어, 734와 893을 칠판에 적었다면, 상수는 이 수를 437과 398로 읽는다. 따라서, 상수는 두 수중 큰 수인 437을 큰 수라고 말할 것이다.

두 수가 주어졌을 때, 상수의 대답을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 칠판에 적은 두 수 A와 B가 주어진다. 두 수는 같지 않은 세 자리 수이며, 0이 포함되어 있지 않다.

출력
첫째 줄에 상수의 대답을 출력한다.

*/

#include <iostream>
#include <string>

#define NONE 1
#define EQUAL 0
#define ONE -1

template<typename T>
int compare(const T& a, const T& b) {
	return a > b ? NONE : (a < b ? ONE : EQUAL);
}


template<typename T>
void reverseCompare(const T& a,const T& b, bool& isOne, short t) {//problem: size_t는 양수만 가능
	if (t < 0)
		return;
	switch (compare(a[t], b[t])) {
	case NONE:
		isOne = false;
		break;//problem 1: switch 분기에 반드시 써줘야 함
	case EQUAL:
		reverseCompare(a, b, isOne, t - 1);
		break;
	default:
		break;//마찬가지
	};
}


int main() {

	std::string strOne{}, strTwo{};
	bool isOne{ true };

	std::cin >> strOne >> strTwo;

	reverseCompare(strTwo, strOne, isOne, 2);

	if (isOne)
		std::cout << strOne[2] << strOne[1] << strOne[0];
	else
		std::cout << strTwo[2] << strTwo[1] << strTwo[0];

	
	

}