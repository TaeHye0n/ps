#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
 int dx[] = { 1, -1, 0, 0 };
 int dy[] = { 0, 0, 1, -1 };
 queue<pair<int, int>> q;
 
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    bool vi[100][100] = {false,};
    
   
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n; j++){
            if( picture[i][j] != 0 && vi[i][j] == false ){
                number_of_area++;
                int size = 0;
                int temp = picture[i][j];
                q.push({i, j});
                vi[i][j] = true;
                size++;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int w = 0; w < 4; w++){
                        int nx = x + dx[w];
                        int ny = y + dy[w];
                        
                        if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                        if(vi[nx][ny] == false && picture[nx][ny] == temp){
                            q.push({nx, ny});
                            vi[nx][ny] = true;
                            size++;
                        }
                    }
                   
                }
                if(size > max_size_of_one_area) max_size_of_one_area = size;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    
    
    return answer;
}