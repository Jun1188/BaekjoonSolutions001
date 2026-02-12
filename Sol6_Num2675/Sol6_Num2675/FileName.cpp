
/*
문제
문자열 S를 입력받은 후에, 각 문자를 R번 반복해 새 문자열 P를 만든 후 출력하는 프로그램을 작성하시오. 즉, 첫 번째 문자를 R번 반복하고, 두 번째 문자를 R번 반복하는 식으로 P를 만들면 된다. 
S에는 QR Code "alphanumeric" 문자만 들어있다.

QR Code "alphanumeric" 문자는 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-./: 이다.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 각 테스트 케이스는 반복 횟수 R(1 ≤ R ≤ 8), 문자열 S가 공백으로 구분되어 주어진다. S의 길이는 적어도 1이며, 20글자를 넘지 않는다.

출력
각 테스트 케이스에 대해 P를 출력한다.

*/


#include <iostream>
#include <memory>



struct STR {

	size_t r{ };
	std::string str{};

};




int main() {

	size_t t{};
	std::cin >> t;

	std::unique_ptr<STR[]> strs{new STR[t]{}};
	
	//std::unique_ptr<std::string> strP{ new std::string[t]{} };
	//unque_ptr은 <string>의 경우 단일 객체만 가능, string[]로 해야 배열 포인터로 작동.
	//다만 range-in for 문이 안되기에 의미론적으로는 vector가 더 적합할 듯?
	//근데 일단 vector 컨테이너는 잘 모르니...

	for (int i = 0; i < t; ++i) {

	
		std::cin >> strs[i].r >> strs[i].str;

	}

	for (int i{}; i < t; ++i) {
		for (char c : strs[i].str) {
			for (int j = 0; j < strs[i].r; ++j) {
				std::cout << c;
			}
		}
		std::cout << std::endl;
	}

	//unique ptr은 RAII를 자동 사용


}


/*
재귀호출을 하려다가 역순호출의 수정이 귀찮아서 포기한 흔적 

template<typename R, typename... STR>
void PrintStrs(size_t r, STR... str);

size_t PrintStr(size_t r, std::string str);


size_t PrintStr(size_t r, std::string str) {

	size_t r{};

	std::cin >> r >> str;
	if (r > 0)
		PrintStr(r - 1);
	for (char c : str) {
		for (int i{}; i < r; ++i)
			std::cout << c;
	}
	std::cout << '\n';

}

*/
