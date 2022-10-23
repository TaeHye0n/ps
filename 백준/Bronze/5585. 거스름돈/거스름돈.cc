#include<iostream>

using namespace std;


int main() {
    int n = 0;
    cin >> n;
    n = 1000 - n;
    int coin[6] = { 500, 100, 50, 10, 5, 1 };
    int answer = 0;
    int idx = 0;
    while (n > 0) {
        answer += n / coin[idx];
        n = n % coin[idx];
        idx++;
    }
    cout << answer;
    return 0;
}