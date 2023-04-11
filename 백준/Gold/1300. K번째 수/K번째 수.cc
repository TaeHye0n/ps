#include <iostream>

using namespace std;

long long N; // 배열의 크기
long long k; // 자연수

long long cnt(long long mid) {
	long long res = 0;
	for (long long i = 1; i <= N; i++) {
		res += min(N, mid / i);
		if (i > mid) break;
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> k;

	long long l = 1;
	long long r = N * N;

	int ans = 0;

	while (l <= r) {
		long long mid = (l + r) / 2;
		if (cnt(mid) < k) l = mid + 1;
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}