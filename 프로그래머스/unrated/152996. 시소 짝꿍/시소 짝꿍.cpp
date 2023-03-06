#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

bool visited[1001][1001];
long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> m;
    set<int> s;
    
    for(int w : weights){
        s.insert(w);
        m[w]++;
    }
    
    for(int w : s){
        long long weightCnt = m[w];
        answer += weightCnt*(weightCnt-1)/2;
        for(int i = 2; i <= 4; i++){
            for(int j = 2; j <= 4; j++){
                if(i == j) continue;
                if((w * i) % j) continue;
                if(m[w*i/j] != 0 && !visited[w*i/j][w]){
                    visited[w*i/j][w] = true;
                    visited[w][w*i/j] = true;
                    answer += m[w*i/j] * m[w];
                }
            }
        }
    }
    
    return answer;
}