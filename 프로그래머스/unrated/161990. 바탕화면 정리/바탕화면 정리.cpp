#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    vector<int> X;
    vector<int> Y;
    
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                Y.push_back(i);
                X.push_back(j);
            }
        }
    }
    
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    
    answer.push_back(Y.front());
    answer.push_back(X.front());
    answer.push_back(Y.back()+1);
    answer.push_back(X.back()+1);
    return answer;
}