#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string from, to;
int ans;

void input() {
	cin >> from >> to;
}

void dfs(string to) {
	if (from == to) {
		ans = 1;
		return;
	}

	if (from.length() >= to.length()) {
		return;
	}
	
	if(to[to.size()-1] == 'A'){
		string temp = to;
		temp.erase(temp.size() - 1);
		dfs(temp);
	}
	if (to[0] == 'B') {
		string temp = to;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		dfs(temp);
	}
}

void solve() {
	dfs(to);
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}