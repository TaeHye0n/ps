#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second

using namespace std;
typedef long long ll;

int M, N; // 조카의 수 M, 과자의 수 N
int arr[1000001];
int main() {
	FAST_IO;
	
	int ans = -1;
	int l = 1, r = 0;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}
	sort(arr, arr + N);

	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			cnt += (arr[i] / mid);
		}

		if (cnt >= M) {
			l = mid + 1;
			ans = max(ans, mid);
		}
		else r = mid - 1;
	}

	ans = ans <= 0 ? 0 : ans;
	cout << ans;
	
	return 0;
}