#include <iostream>
#include <vector>

using namespace std;


const int dy[8] = { 0,0,-1,1,1,1,-1,-1 };
const int dx[8] = { 1,-1,0,0,1,-1,1,-1 };

int N;
vector<pair<int, int>> v(3);

// idx = 0 킹, idx = 1 돌

void setCoordinate(string s, int idx) {
	int x = s[0] - 'A' + 1;
	int y = s[1] -'1' + 1;
	v[idx] = { y,x };
}

char setAlphabet(int a) {
	return a - 1 + 'A';
}

int setDirection(string s) {
	if (s == "R") return 0;
	else if (s == "L") return 1;
	else if (s == "B") return 2;
	else if (s == "T") return 3;
	else if (s == "RT") return 4;
	else if (s == "LT") return 5;
	else if (s == "RB") return 6;
	return 7;
}
void solve() {
	string a, b;
	cin >> a >> b;
	setCoordinate(a,0);
	setCoordinate(b,1);
	cin >> N;

	while (N--) {
		string command;
		cin >> command;
		int dir = setDirection(command);

		int kny = v[0].first + dy[dir];
		int knx = v[0].second + dx[dir];

		if (kny < 1 || knx < 1 || kny > 8 || knx > 8) continue;

		if (kny == v[1].first && knx == v[1].second) {
			int sny = v[1].first + dy[dir];
			int snx = v[1].second + dx[dir];

			if (sny < 1 || snx < 1 || sny > 8 || snx > 8) continue;

			v[1].first = sny;
			v[1].second = snx;
		}

		v[0].first = kny;
		v[0].second = knx;
	}

	cout << setAlphabet(v[0].second) << v[0].first << "\n";
	cout <<setAlphabet(v[1].second) << v[1].first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
	return 0;
}