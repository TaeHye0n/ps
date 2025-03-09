#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"


int N;
string answer;
bool flag;

void recur(string str) {
	if (flag) return;
	int size = str.size();
	for (int i = 1; i <= size / 2; i++) {
		if (str.substr(size - i, i) == str.substr(size - 2 * i, i)) return;
	}

	if (size == N) {
		flag = true;
		answer = str;
	}

	recur(str + "1");
	recur(str + "2");
	recur(str + "3");
}

int main() {
	FAST_IO;

	answer;
	cin >> N;
	recur("");

	cout << answer << endl;

	return 0;
}