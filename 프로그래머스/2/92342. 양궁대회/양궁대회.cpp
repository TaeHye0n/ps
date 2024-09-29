#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;
vector<int> answer(11);
vector<int> infos;
bool answer_changed;
int max_diff;
void dfs(int idx, int cnt, int a_score, int l_score, vector<int> arrows) {
    if (cnt > n) return;
    if (idx == 11) {
        if (cnt != n) {
            arrows[idx - 1] = n - cnt;
        }
        if (l_score <= a_score) return;
        
        if (l_score - a_score > max_diff) {
            max_diff = l_score - a_score;
            answer = arrows;
            
        } else if (l_score - a_score == max_diff) {
            for (int i = 10; i >= 0; i--) {
                if (answer[i] == arrows[i]) continue;
                else {
                    if (answer[i] < arrows[i]) {
                        answer = arrows;
                    }
                    break;
                }
            }
        }
        return;
    }
    
    
    if (infos[idx] < n - cnt) {
        arrows.push_back(infos[idx] + 1);
        dfs(idx + 1, cnt + infos[idx] + 1, a_score, l_score + (10 - idx), arrows);
        arrows.pop_back();
    }
    
    arrows.push_back(0);
    if (infos[idx] > 0) {
        dfs(idx + 1, cnt, a_score + (10 - idx), l_score, arrows);
    } else {
        dfs(idx + 1, cnt, a_score, l_score, arrows);
    }
    arrows.pop_back();
    
}
vector<int> solution(int n1, vector<int> info) {
    infos = info;
    n = n1;
    vector<int> v;
    dfs(0, 0, 0, 0, v);

    if (max_diff == 0) {
        return {-1};
    }
    return answer;
}