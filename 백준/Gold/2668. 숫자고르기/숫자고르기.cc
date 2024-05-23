#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second
using namespace std;

typedef long long ll;

int N; // 1 <= N <= 100
int arr[101];
bool visited[101];
vector<int> ans;


void dfs(int st, int cur) {
    // 방문했던 곳 재방문
    if (visited[cur]) {
        // 사이클이 생기면 추가
        if (st == cur) ans.push_back(st);
        return;
    }

    visited[cur] = true;
    dfs(st, arr[cur]);
}

int main() {
  
    FAST_IO;
 
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto num : ans) {
        cout << num << endl;
    }
    return 0;
    
}