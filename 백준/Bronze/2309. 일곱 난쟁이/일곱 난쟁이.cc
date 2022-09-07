#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> ans;
bool vi[9];
bool flag;
void solve(int cnt, int sum) {
	if (cnt == 7) {
		if (sum == 100) {
			for (int i = 0; i < v.size(); i++) {
				if (vi[i] == true) ans.push_back(v[i]);
			}
			flag = true;
		}
		return;
	 }
	for (int i = 0; i < v.size(); i++) {
		if (flag) break;
		if (vi[i] == false) {
			vi[i] = true;
			solve(cnt + 1, sum + v[i]);
			vi[i] = false;
		}
	}
}
void input() {
	for (int i = 0; i < 9; i++) {
		int tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}
}
int main() {
	input();
	solve(0, 0);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}