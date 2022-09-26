#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    
	int N = 0;
	cin >> N;
	vector<int> v;

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), greater<int>());
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		long long sum = v[i] * (i + 1);
		if (sum > answer) {
			answer = sum;
		}
	}
	cout << answer;
	
	
	return 0;
}
