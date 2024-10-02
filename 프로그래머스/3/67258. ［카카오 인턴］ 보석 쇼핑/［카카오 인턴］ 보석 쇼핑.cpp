#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

// 투포인터 문제 
vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    
    int jewel_cnt = 0;
    set<string> s;
    for (string gem : gems) {
        s.insert(gem);
    }
    jewel_cnt = s.size();
    map<string, int> m;
    
    int st = 0;
    int ed = 0;
    int dist = 100001;
    
    while (st <= ed && ed < gems.size()) {
        m[gems[ed]]++;
        
        while (m.size() == jewel_cnt) {
            if (dist > ed - st + 1) {
                dist = ed - st + 1;
                answer[0] = st + 1;
                answer[1] = ed + 1;
            }
            m[gems[st]]--;
            if (m[gems[st]] <= 0) m.erase(gems[st]);
            st++;
        }
        ed++;
    }

    
    return answer;
}