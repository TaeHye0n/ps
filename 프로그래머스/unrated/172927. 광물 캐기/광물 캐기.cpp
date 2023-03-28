#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int answer = INT_MAX;
vector<int> picks;
vector<string> minerals;
vector<int> mine;

int calculate(int cnt, int i){
    int pick = 0;
    int res = 0;
    if(i == 0) pick = 25;
    else if(i == 1) pick = 5;
    else pick = 1;
    
    for(int i = cnt*5; i < (cnt+1)*5 && i < mine.size(); i++){
        int temp = mine[i] / pick;
        if(temp == 0) res++;
        else res += temp;
    }
    return res;
}
void dfs(int cnt, int res){
    if((picks[0] == 0 && picks[1] == 0 && picks[2] == 0) || cnt*5 >= mine.size()){
        answer = min(answer, res);
        return;
    }
    
    for(int i = 0; i <= 2; i++){
        if(picks[i] != 0){
            picks[i]--;
            dfs(cnt+1, res + calculate(cnt,i));
            picks[i]++;
        }
    }
}

int solution(vector<int> a, vector<string> b) {
    picks = a;
    minerals = b;

    for(string s: minerals){
        if(s == "diamond") mine.push_back(25);
        else if(s == "iron") mine.push_back(5);
        else mine.push_back(1);
    }
    dfs(0,0);
    return answer;
}