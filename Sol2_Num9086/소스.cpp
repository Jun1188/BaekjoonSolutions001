#include <iostream>

//백준 error point
//백준은 라이브러리를 엄격히 따지며, 내가 해당 라이브러리를 적지 않은 부분이 실수
#include <memory> // unique_ptr, make_unique를 위해 필수
#include <string> // string 사용 시 명시하는 것이 표준에 적합


using namespace std;

/*
문제 9086.
문자열을 입력으로 주면 문자열의 첫 글자와 마지막 글자를 출력하는 프로그램을 작성하시오.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 한 줄에 하나의 문자열이 주어진다. 문자열은 알파벳 A~Z 대문자로 이루어지며 알파벳 사이에 공백은 없으며 문자열의 길이는 1000보다 작다.

출력
각 테스트 케이스에 대해서 주어진 문자열의 첫 글자와 마지막 글자를 연속하여 출력한다.

*/


int main() {

	int inputNum{};
	cin >> inputNum;
	unique_ptr<string[]> strp{ make_unique<string[]>(inputNum) };

	for (int i = 0; i < inputNum; ++i) {
		cin >> strp[i];
	
	}
	for (int i = 0; i < inputNum; ++i) {
		cout << strp[i].front() << strp[i].back() << endl;

	}


	
};
