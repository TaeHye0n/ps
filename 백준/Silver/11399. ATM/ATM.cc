#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    
	vector<int> v;

	int N = 0;
	cin >> N;
	
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += v[i] * (N - i);
	}
	cout << answer;

	return 0;
}