#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(),score.end(), greater<int>());
    int idx = 0;
    while(1){
        if(idx+m-1 >= score.size()) break;
        answer += score[idx+m-1]*m;
        idx += m;
    }
    return answer;
}