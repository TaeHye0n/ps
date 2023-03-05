#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int oCnt = 0;
    int xCnt = 0;
    int oLineCnt = 0;
    int xLineCnt = 0;
    
    char arr[2] = {'O','X'};
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'O') oCnt++;
            else if(board[i][j] == 'X') xCnt++;
        }
    }
    
    if(oCnt < xCnt) return 0;
    if(oCnt > xCnt + 1) return 0;
    
    for(int i = 0; i < board.size(); i++){
        if(board[i] == "OOO") oLineCnt++;
        else if(board[i] == "XXX") xLineCnt++;
        
        if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') oLineCnt++;
        else if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') xLineCnt++;
    }
    
    for(char c : arr){
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c){
            if(c == 'O') oLineCnt++;
            else xLineCnt++;
        }
        if(board[0][2] == c && board[1][1] == c && board[2][0] == c){
            if(c == 'O') oLineCnt++;
            else xLineCnt++;
        }
    }
    
    if(oLineCnt + xLineCnt > 1){
        if(oLineCnt == 2 && oCnt - xCnt == 1) return 1;
        return 0;
    }
    
    if(xLineCnt == 1 && oCnt > xCnt) return 0;
    if(oLineCnt == 1 && oCnt == xCnt) return 0;
  
    return answer;
}