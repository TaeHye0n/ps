#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second
using namespace std;

typedef long long ll;

int n; // 회전초밥 개수 2<= n <= 30,000
int d; // 초밥의 가지수 2 <= d <= 3,000
int k; // 연속해서 먹는 접시의 수 2 <= k <= 3,000
int c; // 쿠폰 번호 1 <= c <= d;
bool check[3001];
int main() {
  
    FAST_IO;
 
    cin >> n >> d >> k >> c;

    vector<int> v;

    int ans = -1;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        bool useCoupon = false;
        int cnt = 0;
        for (int j = i; j < i + k; j++) {
            int val = v[j % n];
            if (!check[val]) {
                check[val] = true;
                cnt++;
            }
        }

        if (!check[c]) cnt++;
        ans = max(ans, cnt);
        memset(check, 0, sizeof(check));
    }
    cout << ans;
    return 0;
    
}