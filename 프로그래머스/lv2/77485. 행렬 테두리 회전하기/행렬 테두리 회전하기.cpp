#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[101][101];
vector<int> answer;

void rotate(int y1, int x1, int y2, int x2){
    int min_num = matrix[y1][x1];
    int temp = matrix[y1][x1];
    
    for(int i = y1; i < y2; i++){
        matrix[i][x1] = matrix[i+1][x1];
        min_num = min(min_num, matrix[i][x1]);
    }
    
    for(int i = x1; i < x2; i++){
        matrix[y2][i] = matrix[y2][i+1];
        min_num = min(min_num,matrix[y2][i]);
    }
    
    for(int i = y2; i > y1; i--){
        matrix[i][x2] = matrix[i-1][x2];
        min_num = min(min_num, matrix[i][x2]);
    }
    
    for(int i = x2; i > x1; i--){
        matrix[y1][i] = matrix[y1][i-1];
        min_num = min(min_num, matrix[y1][i]);
    }
    
    matrix[y1][x1+1] = temp;
    answer.push_back(min_num);
    
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int num = 1;
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            matrix[i][j] = num++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        rotate(queries[i][0]-1, queries[i][1]-1, queries[i][2]-1, queries[i][3]-1);
    }
    return answer;
}