#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 캐시 히트 못하면 가장 최근 것을 캐시에 넣고, 제일 오래된 것을 캐시에서 삭제
// 캐시 히트 성공 시 캐시에서 자신을 지우고, 새로 추가
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if (cacheSize == 0) return cities.size() * 5;
    
    for (auto &s : cities) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = toupper(s[i]);
        }
    }
    
    vector<string> cache;
    
    for (int i = 0; i < cities.size(); i++) {
        auto itr = find(cache.begin(), cache.end(), cities[i]);
        
        if (itr == cache.end()) {
            answer += 5;
            if (cache.size() == cacheSize) cache.erase(cache.begin());
        } else {
            answer += 1;
            cache.erase(itr);
        }
        cache.push_back(cities[i]);
    }
    
    
    return answer;
}