#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[101];
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> v;
    
    for(int i = 0; i < cards.size(); i++){
        int cnt = 0;
        int idx = i;
        
        while(1){
            if(visited[idx]){
                if(cnt != 0) v.push_back(cnt);
                break;
            }
            cnt++;
            visited[idx] = true;
            idx = cards[idx] - 1;
        }
    }
    if(v.size() <= 1) return 0;
    sort(v.begin(), v.end());
    return v[v.size()-1] * v[v.size()-2];
    
}