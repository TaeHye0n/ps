#include <string>
#include <vector>
#include <queue>
using namespace std;

int dist[1000001];

int solution(int x, int y, int n) {
    int answer = 0;
    queue<int> q;
    q.push(x);
    for(int i = 0; i < 1000001; i++){
        dist[i] = -1;
    }
    dist[x] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int next : {curr + n, curr * 2, curr * 3}){
            if(next < 0 || next > y) continue;
            if(dist[next] != -1) continue;
            dist[next] = dist[curr]+1;
            q.push(next);
        }
    }
    return dist[y];
}