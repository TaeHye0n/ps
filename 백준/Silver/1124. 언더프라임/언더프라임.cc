#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;
int A, B;
int nums[MAX];
vector<int> primes;

void input() {
	cin >> A >> B;
}

void storePrime() {
	for (int i = 2; i < MAX; i++) {
		nums[i] = i;
	}

	for (int i = 2; i * i < MAX; i++) {
		if (nums[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (nums[j] == j) nums[j] = i;
			}
		}
	}

	for (int i = 2; i < MAX; i++) {
		if (nums[i] == i) primes.push_back(i);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	storePrime();
	int answer = 0;

	for (int i = A; i <= B; i++) {
		int cnt = 0;
		int temp = i;
		for (int j = 0; j < primes.size(); j++) {
			while (temp % primes[j] == 0) {
				cnt++;
				temp /= primes[j];
				if (temp == 1) break;
			}
			if (temp == 1) break;
		}
		if (nums[cnt] == cnt) answer++;
	}
	cout << answer;
	return 0;
}