#include <iostream>


using namespace std;



void starLoop(int blank, int star) {//problem: 인자부터 의미론적으로 맞게 하는 게 규칙상 맞음
	//알고리즘을 내가 최대한 직관적으로 이해가능하게 짜기
	//예외와 현상에 맞게 덕지덕지 붙인 코드는 안좋음
	//적어도 재귀구문에서는 그게 맞는듯(사실 다른 대부분의 코드도)

	
	for (int i = 0; i < blank; ++i)
		cout << ' ';
	for (int i = 0; i < star; ++i)
		cout << '*';
	cout << endl;
	if (blank == 0)
		return;
	starLoop(blank - 1, star + 2);

	for (int i = 0; i < blank; ++i)
		cout << ' ';
	for (int i = 0; i < star; ++i)
		cout << '*';
	cout << endl;

	

}

int main() {

	int cnt;

	cin >> cnt;

	starLoop(cnt-1, 1);

	//size_t starNum{1};
	//반복문으로 풀려한 흔적
	//for (int i = cnt-1; i >= 0; --i) {
	//	for (int j = 0; j < i; ++j) {
	//		cout << ' ';
	//	}
	//	cout << '*';
	//	for (int j = i; j < cnt - 1; ++j) {
	//		cout << "**";
	//	}
	//	cout << endl;
	//}
}