#include<iostream>

using namespace std;

int n;
void input() {
	
	cin >> n;
}

int solve(int n) {
	int cnt = 0;
	while (n >= 0) {
		if (n % 5 == 0) {
			cnt += (n / 5);
			return cnt;
		}
		n -= 3;
		cnt++;
	}
	
	return -1;
}
int main() {
	input();
	cout << solve(n);
	
	return 0;
}