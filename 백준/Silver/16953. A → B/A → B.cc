#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int A, B, ans;


void input() {
    cin >> A >> B;
}
void solve() {
    while (1) {
        if (A > B) {
            cout << -1;
            break;
        }
        ans++;
        if (B == A) {
            cout << ans;
            break;
        }
        if (B % 10 == 1) {
            B--;
            B /= 10;
        }
        else if (B % 2 == 0) {
            B /= 2;
        }
        else {
            cout << -1;
            break;
        }
    }

}

int main() {
    input();
    solve();
    
    return 0;
}