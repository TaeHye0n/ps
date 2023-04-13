#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    answer++;
    int curcctv = routes[0][1];
    for(int i = 1; i < routes.size(); i++){
        if(curcctv < routes[i][0]){
            answer++;
            curcctv = routes[i][1];
        }
    }
    return answer;
}