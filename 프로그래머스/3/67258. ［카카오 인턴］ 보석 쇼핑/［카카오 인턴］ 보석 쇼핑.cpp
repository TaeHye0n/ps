#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s;
    for (auto g : gems) {
        s.insert(g);
    }
    int cnt = s.size();
    
    int st = 0;
    int ed = 0;
    int dist = 100001;
    map<string, int> m;
    
    
    while (st <= ed && ed < gems.size()) {
        m[gems[ed]]++;
        
        while (m.size() == cnt) {
            if (ed - st + 1 < dist) {
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