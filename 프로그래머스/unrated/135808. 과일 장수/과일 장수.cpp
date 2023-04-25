#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    vector<int> box;
    sort(score.begin(), score.end());
    int idx = score.size()-1;
    while(1)
    {
        if(idx < 0){
            break;
        }
        if(box.size() < m)
        {
                box.push_back(score[idx]);
                idx--;
        }
        
        if(box.size() == m)
        {
            answer += box.back() * box.size();
            box.clear();
        }
    }
    return answer;
}