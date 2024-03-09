#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int> &v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] > v2[0];
}


int solution(vector<vector<int>> scores) {
    int answer = 1;
    vector<int> target = scores[0];
    int targetSum = target[0] + target[1];
    
    int max = -1;
    
    sort(scores.begin(), scores.end(), cmp);
    
    for (auto score : scores) {
        if (max < score[1]) max = score[1];
        else if(max > score[1]) {
            if (target[0] == score[0] && target[1] == score[1]) return -1;
            continue;
        }
        if (score[0] + score[1] > targetSum) answer++;
    }
    return answer;
}