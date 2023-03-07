#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(int time: works) pq.push(time);
    
    while(n>0){
        int temp = pq.top();
        pq.pop();
        temp--;
        pq.push(temp);
        n--;
    }
    if(pq.top() <= 0) return 0;
    while(!pq.empty()){
        answer += (long long)pow(pq.top(),2);
        pq.pop();
    }
    return answer;
}