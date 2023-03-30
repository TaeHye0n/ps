/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int saw[4][8];
int K;
vector<pair<int, int>> cmd;

void rotate(int num, int dir) {
    if (dir == 1) {
        int temp = saw[num][7];
        for (int i = 7; i > 0; i--) {
            saw[num][i] = saw[num][i - 1];
        }
        saw[num][0] = temp;
    }

    else if (dir == -1) {
        int temp = saw[num][0];
        for (int i = 0; i < 7; i++) {
            saw[num][i] = saw[num][i + 1];
        }
        saw[num][7] = temp;
    }
    else return;
}

void solve() {
    for (int i = 0; i < K; i++) {
        int num = cmd[i].first;
        int dir = cmd[i].second;
        num--;
        vector<int> v(4);
        v[num] = dir;
        for (int i = num; i < 3; i++) {
            if (saw[i][2] == saw[i + 1][6]) v[i + 1] = 0;
            else v[i + 1] = -v[i];
        }
        for (int i = num; i > 0; i--) {
            if (saw[i][6] == saw[i - 1][2]) v[i - 1] = 0;
            else v[i - 1] = -v[i];
        }

        for (int i = 0; i < 4; i++) {
            rotate(i, v[i]);
        }
    }
}

void input() {
    cin >> K;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> saw[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        cmd.push_back({ a,b });
    }
}

int cal() {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (saw[i][0] == 1) ans += pow(2, i);
    }
    return ans;
}
int main(int argc, char** argv) {
    int T;
    cin >> T;
    int cnt = 0;
    while (T--) {
        cmd.clear();
        input();
        solve();
        cout << "#" << ++cnt << " " << cal() << "\n";

    }
    return 0;
}