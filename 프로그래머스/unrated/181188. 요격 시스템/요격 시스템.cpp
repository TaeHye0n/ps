#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(),cmp);
    
    answer++;
    int point = targets[0][1];
    for(int i = 1; i < targets.size(); i++){
        if(targets[i][0] >= point){
            point = targets[i][1];
            answer++;
        }
    }
    return answer;
}