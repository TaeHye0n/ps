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

int N; // 휴게소의 개수 N
int M; // 더 지으려고 하는 휴게소의 개수 M
int L; // 고속도로의 길이 L
vector<int> pos; // 시작점, 끝점, 휴게소의 위치

int main() {
	FAST_IO;
	cin >> N >> M >> L;
	int ans = L;

	pos.push_back(0); // 시작점
	pos.push_back(L); // 끝점
	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		pos.push_back(a);
	}

	sort(pos.begin(), pos.end());

	int l = 1; int r = L - 1; // 고속도로 양 끝에 휴게소를 지을 수 없다.

	while (l <= r) {
		int total_count = 0;
		int mid = (l + r) / 2;

		for (int i = 1; i < pos.size(); i++) {
			int len = pos[i] - pos[i - 1]; // 두 휴게소 사이의 거리

			int can_build_cnt = len / mid;

			if (can_build_cnt > 0) {
				if (len % mid == 0) total_count += --can_build_cnt; // 거리가 mid로 나누어 떨어지는 것은 pos[i] 휴게소에도 설치했다는 의미
				else total_count += can_build_cnt;
			}
		}
		if (total_count > M) l = mid + 1; // 개수 M을 초과했으니 간격을 좁혀 준다.
		else {
			r = mid - 1;
			ans = min(ans, mid);
		}
	}
	cout << ans;
	return 0;
}