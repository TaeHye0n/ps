#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
    
	int N = 0;
	cin >> N;
	vector<int> A;
	vector<int> B;

	int tmp = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		A.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		B.push_back(tmp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += A[i] * B[i];
	}
	cout << answer;
	
	return 0;
}
