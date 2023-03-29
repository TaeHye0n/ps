#include<iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;
int arr[17][17];
bool visited[17];
int ans;
int N;

int getSub(vector<int>& c1, vector<int>& c2) {
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < N/2; j++) {
			if (i == j) continue;
			sum1 += arr[c1[i]][c1[j]];
			sum2 += arr[c2[i]][c2[j]];
		}
	}

	return abs(sum1 - sum2);
}
void comb(int idx, int cnt) {
	if (cnt == N / 2) {
		vector<int> v1, v2;
		for (int i = 0; i < N; i++) {
			if (visited[i]) v1.push_back(i);
			else v2.push_back(i);
		}

		ans = min(ans, getSub(v1, v2));
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			comb(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 

	
	int T;
	int cnt = 1;
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	while (T--) {
		ans = INT_MAX;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		comb(0, 0);

		cout << "#" << cnt++ << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}