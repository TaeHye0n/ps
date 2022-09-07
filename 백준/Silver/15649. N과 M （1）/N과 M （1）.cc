#include<iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
bool vi[9];
int arr[9];
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
}
void print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}
void dfs(int cnt) {
	if (cnt == m) {
		print();
		return;
	}

	for (int i = 0; i < n; i++) {
		if (vi[i] == true) continue;
		vi[i] = true;
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
		vi[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	dfs(0);
	return 0;
}