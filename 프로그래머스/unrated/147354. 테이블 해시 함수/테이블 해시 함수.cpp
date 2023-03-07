#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int column;

bool cmp(const vector<int> &v1, const vector<int> &v2){
    if(v1[column] == v2[column]) return v1[0] > v2[0];
    return v1[column] < v2[column];
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;
    
    sort(data.begin(), data.end(), cmp);
    
    for(int i = row_begin; i <= row_end; i++){
        int sum = 0;
        for(int j = 0; j < data[i-1].size(); j++){
            sum += data[i-1][j]%i;
        }
        answer ^= sum;
    }
    
    return answer;
}