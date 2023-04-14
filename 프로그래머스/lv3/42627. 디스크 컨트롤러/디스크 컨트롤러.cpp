#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp{
    bool operator()(vector<int> v1, vector<int> v2){
        return v1[1] > v2[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    int idx = 0, curTime = 0;
    int sum = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while(!(idx >= n && pq.empty())){
        if(idx < n && curTime >= jobs[idx][0]){
            pq.push(jobs[idx]);
            idx++;
            continue;
        }
        
        if(!pq.empty()){
            curTime += pq.top()[1];
            sum += (curTime-pq.top()[0]);
            pq.pop();
        }
        else curTime = jobs[idx][0];
    }
    answer = sum/n;
    return answer;
}