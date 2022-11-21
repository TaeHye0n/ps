#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int N;
vector<string> ans;
vector<char> v;

bool isZero(string s) {
	string temp = "";
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ' || s[i] == '+' || s[i] == '-') {
			if (s[i] == ' ') continue;
			else sum += stoi(temp);
			temp = "";
		}
		temp += s[i];
	}
	sum += stoi(temp);
	if (sum == 0) return true;
	return false;
}

void dfs(string s, int depth) {

	if (depth == N) {
		if(isZero(s)) ans.push_back(s);
		return;
	}
	dfs(s + "+" + v[depth], depth + 1);
	dfs(s + " " + v[depth], depth + 1);
	dfs(s + "-" + v[depth], depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {

		cin >> N;
		ans.clear();
		v.clear();
		for (int i = 1; i <= N; i++) {
			v.push_back(i + '0');
		}
		dfs("1", 1);
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
		cout << "\n";
	}
}