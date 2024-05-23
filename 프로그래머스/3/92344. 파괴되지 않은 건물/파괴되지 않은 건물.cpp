#include <string>
#include <vector>

using namespace std;

// n, m <= 1,000
// skill.size() <= 250,000
// 2차원 누적합을 사용해야 효율성 통과 가능
int n, m;
int prefixSum[1002][1002];

int solution(vector<vector<int>> boards, vector<vector<int>> skills) {
    int answer = 0;
    n = boards.size();
    m = boards[0].size();
    
    for (auto skill : skills) {
        int type = skill[0];
        int r1 = skill[1], c1 = skill[2];
        int r2 = skill[3], c2 = skill[4];
        int degree = skill[5];
        
        if (type == 1) degree *= -1;
        
        prefixSum[r1][c1] += degree;
        prefixSum[r2 + 1][c2 + 1] += degree;
        prefixSum[r1][c2 + 1] -= degree;
        prefixSum[r2 + 1][c1] -= degree;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefixSum[i][j + 1] += prefixSum[i][j];
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            prefixSum[j + 1][i] += prefixSum[j][i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (boards[i][j] + prefixSum[i][j] >= 1) answer++;
        }
    }
    
    return answer;
}