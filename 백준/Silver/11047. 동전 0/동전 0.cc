#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
	int N, K = 0;
	cin >> N >> K
		;
	vector<int> v;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		if (K % v[i] != K) {
			answer += K / v[i];
			K %= v[i];
		}
	}

	cout << answer;
	return 0;
}