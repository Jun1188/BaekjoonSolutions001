/*

문제
영어 대소문자와 공백으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

입력
첫 줄에 영어 대소문자와 공백으로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 공백 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열은 공백으로 시작하거나 끝날 수 있다.

출력
첫째 줄에 단어의 개수를 출력한다.

*/

#include <iostream>
#include <string>




int main() {

	std::string str;
	/* 
	problem: cin은 string에 대해 ws 단위로 입력을 받음. 따라서 단어가 아니라 문장 입력 시 오류 발생

	searching result
	std::cin >> str;은 basic_istream::operator>>가 제공하는 서식화 입력을 사용하며, 기본 플래그 skipws 때문에 앞선 공백을 모두 건너뛰고 다음 공백(스페이스, 탭, 개행 등)을 만나면 추출을 멈춥니다.
	공백을 포함해 한 줄 전체를 읽고 싶다면 std::getline(std::cin, str);을 쓰거나, 반드시 토큰 단위로 읽되 공백도 문자 그대로 받고 싶다면 추출 전에 std::cin >> std::noskipws;처럼 조절해야 합니다.
	
	*/

	std::getline(std::cin, str);

	size_t cnt{};
	bool checkIn{ false };
	//if (str[0] == ' ')
		//str[0] = '0';
	
	for (char c : str) {//string은 begin과 end를 지원하므로 range-in이 가능, 또한 string이므로 char 단위
		
		if (c != ' ' && checkIn == false) { //problem 2:
			//checkIn 변수의 if문 조건을 잘못 설정했음. 맨처음에 공백을 받는 경우를 대비해 첫 공백을 문자로 변환했지만, 
			// 그것 때문에 공백만 입력한 경우 cnt가 1이 되는 오류 발생
			// 이러한 오류의 근본 원인은 해당 케이스만 if로 따로 처리해 for문 내부의 하나의 논리구조에서 벗어나면서 새로운 edge가 발생했기 때문
			//그래서 if-else if 내부의 논리로 병합해 처리하여 해결
			//다만 다음에는 이 문제와 별개로 switch룰 쓰는 게 좋을 둣
			checkIn = true;
			++cnt;
		}
		else if (c == ' ') {
			checkIn = false;
		}
		
	}

	std::cout << cnt;



}