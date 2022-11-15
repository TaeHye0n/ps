#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long A = 0, B = 0;
	cin >> A >> B;
	long long GCD = gcd(A, B);
	while (GCD--) {
		cout << 1;
	}
	return 0;
}