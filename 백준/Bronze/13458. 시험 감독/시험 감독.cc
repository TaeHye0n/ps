#include<iostream>
using namespace std;

int N, B, C;
int arr[1000000];
long long answer;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		arr[i] -= B;
		answer++;
		if (arr[i] > 0) {
			answer += (arr[i] - 1) / C + 1;
		}
	}
	cout << answer;

	return 0;
}