#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;
int answer = 0;
int m;
map<int, set<int>> ma;

void makeComb(int st, vector<int> v, int n, vector<int> ans) {
    if (v.size() == 5) {
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < v.size(); j++) {
                if (ma[i].find(v[j]) != ma[i].end()) {
                    cnt++;
                }
                if (cnt > ans[i]) break;
            }
            if (cnt != ans[i]) {
                return;
            }
        }
        answer++;
        return;
    }
    for (int i = st + 1; i <= n; i++) {
        v.push_back(i);
        makeComb(i, v, n, ans);
        v.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    vector<int> v;
    for (int i = 0; i < q.size(); i++) {
        for (int j = 0; j < q[i].size(); j++) {
            ma[i].insert(q[i][j]);
        }
    }
    m = q.size();
    makeComb(0, v, n, ans);
    return answer;
}