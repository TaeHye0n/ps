#include <string>
#include <vector>
#include <map>

#define MAX 101
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};


int n, x;
map<pair<pair<int ,int>, int>, int> m;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    n = points.size(); // 물류 센터의 개수
    x = routes.size(); // 로봇의 개수
    
    int time = 0;
    for (vector<int> route : routes) {
        time = 0;
        pair<int ,int> last;
        for (int i = 0; i < route.size() - 1; i++) {
          int st_idx = route[i];
          int ed_idx = route[i + 1];
          st_idx--;
          ed_idx--;
          pair<int, int> st = { points[st_idx][0], points[st_idx][1] };
          pair<int, int> ed = { points[ed_idx][0], points[ed_idx][1] };
          last = ed;
          while (st != ed) {
              m[{st, time}]++;
            
              int y_diff = st.first - ed.first;
              int x_diff = st.second - ed.second;
            
              if (y_diff != 0) {
                  if (y_diff < 0) st.first++;
                  else st.first--;
              } else if (x_diff != 0) {
                  if (x_diff < 0) st.second++;
                  else st.second--;
               }
               time++;
              }
          }
        m[{last, time}]++;
    }
    
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second >= 2) answer++;
    }
    return answer;
}