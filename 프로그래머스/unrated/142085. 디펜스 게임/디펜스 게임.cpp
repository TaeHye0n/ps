#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

bool notEnd;
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i = 0; i < enemy.size(); i++){
        n -= enemy[i];
        pq.push(enemy[i]);
        if(n < 0){
            if(k > 0){
                k--;
                n += pq.top();
                pq.pop();
            }
            else{
                answer = i;
                notEnd = true;
                break;
            }
        }

    }
    if(!notEnd) answer = enemy.size();
    return answer;
}