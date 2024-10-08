#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

// 방향키는 한 칸 이동
// ctrl + 방향키는 방향에 있는 가장 가까운 카드로 한번에 이동 없으면 마지막 칸
// 카드 또는 빈 공간이 없어 이동 불가하면 커서는 움직이지 않는다

// enter 앞연이 한장이면 두 번째 카드 enter 할 때 까지 유지
// 같은 그림이면 해당 카드들이 사라지고, 다르면 다시 뒤집

// 모든 카드 제거 위한 키조작 횟수 최솟값 찾기 
// 1. ctrl + 방향키도 1번의 조작 횟수로 간주
// 2. 카드는 1~ 6까지 각 각 두장씩만 존재할 수 있다 -> 카드 번호 순열 6!
// 3. 순열을 가지고 bfs 돌리자 -> 6! * 4 * 4

const int INF = 987654321;
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

struct card {
    int y, x;
};
struct pos {
    int y, x, cost;
};

vector<card> cards[7];
vector<int> card_nums;


int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            if (board[i][j] != 0) {
                if (cards[board[i][j]].size() == 0) {
                    card_nums.push_back(board[i][j]);
                }
                cards[board[i][j]].push_back({i, j});
            }
        }
    }
    
    sort(card_nums.begin(), card_nums.end());
    
    do {
        int st_y = r;
        int st_x = c;
        vector<vector<int>> new_board = board;
        int total_cost = 0;
        
        for (int i = 0; i < card_nums.size(); i++) {
            for (int j = 0; j < 2; j++) {
                queue<pos> q;
                bool vi[4][4] = {false ,};
                q.push({st_y, st_x, 0});
                vi[st_y][st_x] = true;
                while (!q.empty()) {
                    int cy = q.front().y;
                    int cx = q.front().x;
                    int cost = q.front().cost;
                    q.pop();
                    
                    if (new_board[cy][cx] == card_nums[i]) {
                        total_cost += cost + 1;
                        new_board[cy][cx] = 0;
                        st_y = cy;
                        st_x = cx;
                        break;
                    }
                    
                    for (int w = 0; w < 4; w++) {
                        int ny = cy + dy[w];
                        int nx = cx + dx[w];
                        
                        if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
                        
                        vi[ny][nx] = true;
                        q.push({ny, nx, cost + 1});
                    }
                    
                    for (int w = 0; w < 4; w++) {
                        int ny = cy;
                        int nx = cx;
                        
                        while (1) {
                            ny += dy[w];
                            nx += dx[w];
                            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) {
                                ny -= dy[w];
                                nx -= dx[w];
                                break;
                            }
                            if (new_board[ny][nx] != 0) break;
                        }
                        
                        vi[ny][nx] = true;
                        q.push({ny, nx, cost + 1});
                    }
                }
            }
        }
        
        answer = min(answer, total_cost);
    }while(next_permutation(card_nums.begin(), card_nums.end()));
    
    
    return answer;
}