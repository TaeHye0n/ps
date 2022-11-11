#include <string>
#include <vector>

using namespace std;
int N;
int maxDiff;
vector<int> ans;
vector<int> apeach;
vector<int> lion;

void dfs(int idx, int cnt, int apeachScore, int lionScore){
    if(idx == 11){
        if(apeachScore >= lionScore) return;
        lion[10] += N - cnt;
        if(lionScore - apeachScore > maxDiff){
            ans = lion;
            maxDiff = lionScore - apeachScore;
        }
        else if(lionScore - apeachScore == maxDiff){
            for(int i = 10; i >= 0; i--){
                if(lion[i] == ans[i]) continue;
                else {
                    if(lion[i] > ans[i]){
                        ans = lion;
                    }
                    break;
                }
            }
        }
        return;
    }
    
    int arrow = apeach[idx] + 1;
    if(arrow + cnt <= N){
        int nextApeachScore = apeachScore;
        int nextLionScore = lionScore + (10-idx);
        if(arrow != 1) nextApeachScore -= (10-idx);
        lion.push_back(arrow);
        dfs(idx+1, cnt+arrow, nextApeachScore, nextLionScore);
        lion.pop_back();
    }
    
    lion.push_back(0);
    dfs(idx+1,cnt, apeachScore, lionScore);
    lion.pop_back();
    
}

vector<int> solution(int n, vector<int> info) {
    N = n;    
    apeach = info;
    
    int apeachScore = 0;
    for(int i = 0; i< info.size(); i++){
        if(info[i] != 0){
            apeachScore += (10-i);
        } 
    }
    dfs(0,0,apeachScore, 0);
    
    if(maxDiff == 0) ans.push_back(-1);
    return ans;
}