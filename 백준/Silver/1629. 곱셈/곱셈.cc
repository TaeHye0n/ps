#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull A, B, C;


ull recur(ull B) {
	if (B == 0) return 1;
	if (B == 1) return A % C;

	ull temp = recur(B / 2) % C;
	if (B % 2 == 0) return temp * temp % C;
	return temp * temp % C * A % C;
}
void solve() {
	cin >> A >> B >> C;
	
	cout << recur(B);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
	return 0;
}