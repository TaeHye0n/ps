#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

string N;
string answer;

void input() {
    cin >> N;
}
void solve() {
    sort(N.begin(), N.end(), greater<>());
    long long sum = 0;
    if (N[N.length() - 1] != '0') {
        answer = "-1";
    }
    else {
        for (char c : N) {
            sum += c;
        }
        if (sum % 3 == 0) {
            answer = N;
        }
        else {
            answer = "-1";
        }
    }

}

int main() {
    input();
    solve();
    cout << answer;
    return 0;
}