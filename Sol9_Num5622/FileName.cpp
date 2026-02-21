/*
전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다. 숫자를 하나 누르면 다이얼이 처음 위치로 돌아가고, 다음 숫자를 누르려면 다이얼을 처음 위치에서 다시 돌려야 한다.
숫자 1을 걸려면 총 2초가 필요하다. 1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.
상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다. 즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다. 예를 들어, UNUCIC는 868242와 같다.

할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 최소 시간을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 알파벳 대문자로 이루어진 단어가 주어진다. 단어의 길이는 2보다 크거나 같고, 15보다 작거나 같다.

출력
첫째 줄에 다이얼을 걸기 위해서 필요한 최소 시간을 출력한다.
*/

#include <iostream>

void calcul(char c, short& cnt, bool& overSvn);


//글자별 기본 계산식
//(alpha - 'A') > 3*n + 2, n + 2 == dyal 
// range - dyal
// 012 2 
// 345 3 
// 678 4
// ..
// n == 5? -> 예외처리 15 16 17 18 7
// (alpha - 'A') > 3*(n+1) 
// 19 20 21 
// 22 23 24 25 -> 25 - 3*7 <= 0
//ms += dyal + 1

int main() {
	//problem 1: 규칙 이해 못함 문제
	// 알파벳 - 숫자 대응 규칙을 이해 못했는데, 알고보니 A~C까지는 1,  D~F는 2, 이런 식이었다
	//다이얼을 안써본 사람들에게는 설명이 불친절하기도 하고, 내 이해력이 딸렸기도 하고..


	/*
	* 
	problem 3: 수정 전
	short cnt{ 0 };
	bool overSvn = false;
	
	*/
	

	size_t ms{};

	std::string str{};

	std::cin >> str;

	for (char c : str) {
		short cnt{ 0 };
		bool overSvn = false; 
		calcul(c, cnt, overSvn);
		ms += cnt + 3;

		//overSvn = false;
		//cnt = 0;
		//problem 3: 선 동기화를 한 후 반복문을 다시 돌 때는 초기화해야 함?
		//차라리 반복문 내부에 선언해 range 변경 -> cnt와 overSvn은 글자에 종속적이면서 글자별 시간 카운트에는 비종속적이므로 이게 의미적으로 더 맞음

	}

	std::cout << ms;


}

void calcul(char c, short& cnt, bool& overSvn) {


	if (cnt == 5)
		overSvn = true;//problem 2: overSvn을 동기화를 안해서 재귀호출 시 false로 되는 문제 발생 

	if (c - 'A' > cnt * 3 + 2 + overSvn && cnt < 7) {
		cnt += 1;
		calcul(c, cnt, overSvn);
	}

	return;

}