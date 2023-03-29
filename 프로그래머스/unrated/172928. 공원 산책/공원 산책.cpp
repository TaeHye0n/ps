#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int y, x;
    
    for(int i = 0; i < park.size(); i++){
        for(int j = 0; j < park[0].length(); j++){
            if(park[i][j] == 'S'){
                y = i;
                x = j;
            }
        }
    }
    
    for(string query : routes){
        char dir = query[0];
        int mount = query[2] - '0';
        int w;
        if(dir == 'E') w = 2;
        else if(dir == 'N') w = 1;
        else if(dir == 'S') w = 0;
        else w = 3;
        
        int ny = y;
        int nx = x;
        bool flag = false;
        for(int i = 0; i < mount; i++){
            ny += dy[w];
            nx += dx[w];
            
            if(ny < 0 || nx < 0 || ny >= park.size() || nx >= park[0].length() || park[ny][nx] == 'X') {
                flag = true;
                break;
            }
            
        }
        if(flag) continue;
        y = ny;
        x = nx;
    }
    
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}