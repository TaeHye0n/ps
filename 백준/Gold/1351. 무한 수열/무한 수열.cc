#include <iostream>
#include <map>
using namespace std;


long long N, P, Q;
map<long long, long long> m;
void input() {
	cin >> N >> P >> Q;
}

long long solve(long long n) {
	if (n == 0) return 1;
	if (m.find(n) != m.end()) return m[n];
	return m[n] = solve(n / P) + solve(n / Q);
}
int main() {
	input();
	cout << solve(N);
	
	return 0;
}