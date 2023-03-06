#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[1001][1001];
    
    int dir = 0;
    int x = 0, y = 0;
    int stNum = 1;
    
    for(int i = 0; i < n; i++){
        if(dir == 0){
            for(int j = i ; j < n; j++){
                arr[y++][x] = stNum++;
            }
            y--;
            x++;
            dir = 1;
        }
        
        else if(dir == 1){
            for(int j = i; j < n; j++){
                arr[y][x++] = stNum++;
            }
            y--;
            x -= 2;
            dir = 2;
        }
        
        else if(dir == 2){
            for(int j = i; j < n; j++){
                arr[y--][x--] = stNum++;
            }
            y += 2;
            x++;
            dir = 0;
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}