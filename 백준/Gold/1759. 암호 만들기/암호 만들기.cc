#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define first Y
#define second X
#define endl "\n"
using namespace std;
typedef long long ll;


vector<char> v;
int L; // 암호의 길이
int C; // 알파벳 종류 개수
vector<string> ans;
string pwd;

bool is_vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void recur(int idx, int depth) {
    if (depth == L) {
        int cnt1 = 0, cnt2 = 0; // 모음과 자음의 개수 카운팅
        for (auto c: pwd) {
            if (is_vowel(c)) cnt1++;
            else cnt2++;
        }

        // 암호는 모음 1개 이상 && 자음 2개 이상 으로 구성
        if (cnt1 >= 1 && cnt2 >= 2) {
            ans.push_back(pwd);
        }
        return;
    }

    for (int i = idx; i < C; i++) {
        pwd += v[i];
        recur(i + 1, depth + 1);
        pwd = pwd.substr(0, pwd.size() - 1);
    }
}

int main() {
    FAST_IO;
    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char c;
        cin >> c;
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    recur(0, 0);

    for (string &s: ans) {
        cout << s << endl;
    }
    return 0;
}

