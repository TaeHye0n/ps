#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> nums;
int ans;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input = 0;
		cin >> input;
		nums.push_back(input);
	}
}

void solve() {
	sort(nums.begin(), nums.end());
	for (int i = 0; i < N; i++) {
		int value = nums[i];
		int l = 0, r = N - 1, sum = 0;
		while (l < r) {
			sum = nums[l] + nums[r];
			if (value == sum) {
				if (l != i && r != i) {
					ans++;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (value < sum) r--;
			else l++;
		}
	}
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}