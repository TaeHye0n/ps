#include<iostream>

using namespace std;

int n, m;

bool vi[9];
int arr[9];
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}
}
void print() {
	for (int i = 0; i < n; i++) {
		if(vi[i] == true) cout << arr[i] << " ";
	}
	cout << "\n";
}
void dfs(int idx,int cnt) {
	if (cnt == m) {
		print();
		return;
	}

	for (int i = idx; i < n; i++) {
		if (vi[i] == true) continue;
		vi[i] = true;
		dfs(i,cnt + 1);
		vi[i] = false;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	input();
	dfs(0, 0);
	return 0;
}