#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

#define INF 987654321
using namespace std;

long long dist[201][201];
long long solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INT_MAX;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            dist[i][j] = 987654321;
        }
    }
    
    for (auto fare : fares) {
        dist[fare[0]][fare[1]] = fare[2];
        dist[fare[1]][fare[0]] = fare[2];
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    
    return answer;
}