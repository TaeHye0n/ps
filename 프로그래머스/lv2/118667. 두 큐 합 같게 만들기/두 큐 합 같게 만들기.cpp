#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0, sum2 = 0;
    queue<int> q1, q2;
    
    for(int n: queue1){
        sum1 += n;
        q1.push(n);
    }
    for(int n2: queue2){
        sum2 += n2;
        q2.push(n2);
    }
    
    int idx = 0, idx2 = 0;
    int maxidx = queue1.size() + queue2.size();
    while(idx < maxidx && idx2 < maxidx){
        if(sum1 == sum2){
            return answer;
        }
        else{
            answer++;
            if(sum1 < sum2){
                int tmp = q2.front();
                q2.pop();
                q1.push(tmp);
                sum1 += tmp;
                sum2 -= tmp;
                idx2++;
            }
            else{
                int tmp = q1.front();
                q1.pop();
                q2.push(tmp);
                sum1 -= tmp;
                sum2 += tmp;
                idx++;
            }
        }
    }
    return -1;
}