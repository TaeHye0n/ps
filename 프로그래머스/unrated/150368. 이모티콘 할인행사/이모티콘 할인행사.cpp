#include <string>
#include <vector>

using namespace std;
int rate[4] = {10,20,30,40}; // 할인율
int maxCnt; // 서비스 가입자
int maxSum; // 판매액
int n; // 이모티콘 개수
vector<int> combinations[16385];
int vectorIdx = 0;
void makeComb(int cnt, vector<int> temp){
    if(cnt == n){
        combinations[vectorIdx] = temp;
        vectorIdx++;
        return;
    }
    
    for(int i = 0; i < 4; i++){
        temp.push_back(rate[i]);
        makeComb(cnt+1, temp);
        temp.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    n = emoticons.size();
    vector<int> temp;
    makeComb(0,temp);
    
    for(int i = 0; i < 16385; i++){
        int cntSum = 0;
        int sumSum = 0;
        for(int j = 0; j < users.size(); j++){
            int overRate = users[j][0];
            int overPrice = users[j][1];
            int tempSum = 0;
            for(int k = 0; k < combinations[i].size(); k++){
                if(combinations[i][k] >= overRate){
                    tempSum += emoticons[k] * (100-combinations[i][k]) / 100;
                }
            }
            if(tempSum >= overPrice){
                tempSum = 0;
                cntSum++;
            }
            sumSum += tempSum;
        }
        if(cntSum > maxCnt){
            maxCnt =cntSum;
            maxSum = sumSum;
        }
        else if(cntSum == maxCnt && maxSum < sumSum){
            maxSum = sumSum;
        }
    }
    answer.push_back(maxCnt);
    answer.push_back(maxSum);
    return answer;
}