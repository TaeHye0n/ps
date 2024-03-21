#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX 10000001

int cnt[MAX];
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for (int size : tangerine) {
        cnt[size - 1]++;
    }
    
    sort(cnt, cnt + MAX, greater<int>());
    
    for (int i = 0; i < MAX; i++) {
        int c = cnt[i];
        k -= c;
        answer++;
        
        if (k <= 0) return answer;
    }
    return answer;
}