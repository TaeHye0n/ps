#include <iostream>
#include <vector>

#define MAX 31
using namespace std;

int D; // 넘어온 날
int K; // D날 준 떡의 개수

int x[MAX];
int y[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> D >> K;

	x[1] = 1;
	x[2] = 0;
	y[1] = 0;
	y[2] = 1;

	for (int i = 3; i <= D; i++) {
		x[i] = x[i - 1] + x[i - 2];
		y[i] = y[i - 1] + y[i - 2];
	}

	for (int i = 1; i <= K; i++) {
		int Y = K - (x[D] * i);
		if (Y % y[D] == 0) {
			cout << i << "\n";
			cout << Y / y[D];
			break;
		}
	}
	return 0;
}