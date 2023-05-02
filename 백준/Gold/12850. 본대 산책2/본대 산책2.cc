#include <iostream>
#include <vector>

#define mod 1000000007;

typedef long long ll;
using namespace std;

int D;
// 0 학생회관 1 진리관 2 신양관 3 전산관
// 4 정보과학관 5 형남공학관 6 환경적기념관 7 미래관
const vector<vector<ll>> campus = {
	{0, 1, 0, 0, 0, 1, 0, 0},
	{1, 0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 1, 0, 0, 1, 1},
	{0, 0, 1, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0},
	{0, 1, 1, 0, 0, 1, 0, 1},
	{0, 0, 1, 1, 1, 0, 1, 0}
};

vector<vector<ll>> oper(const vector<vector<ll>> v1, const vector<vector<ll>> v2) {
	vector<vector<ll>> res(8, vector<ll>(8));
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 8; k++) {
				res[i][j] += (v1[i][k] * v2[k][j]);
				res[i][j] %= mod;
			}
		}
	}

	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> D;
	vector<vector<ll>> temp = campus;
	vector<vector<ll>> ans(8, vector<ll>(8));
	for (int i = 0; i < 8; i++) {
		ans[i][i] = 1;
	}

	while (D) {
		if (D % 2 != 0) {
			ans = oper(ans, temp);
		}
		temp = oper(temp, temp);
		D /= 2;
	}
	cout << ans[4][4];
	return 0;
}