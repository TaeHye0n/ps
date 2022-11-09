#include <iostream>

using namespace std;

int A, B, C;

int main() {
	while (cin >> A >> B >> C) {
		cout << max(C - B, B - A) - 1 << "\n";
	}
	return 0;
}