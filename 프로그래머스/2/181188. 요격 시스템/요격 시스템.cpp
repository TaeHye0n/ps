#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), cmp);
    
    int point = targets[0][1];
    answer++;
    
    for (int i = 1; i < targets.size(); i++) {
        if (point <= targets[i][0]) {
            point = targets[i][1];
            answer++;
        }
    }
    return answer;
}