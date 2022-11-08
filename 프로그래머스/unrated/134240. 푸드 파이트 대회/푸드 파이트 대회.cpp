#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for(int i =1; i < food.size(); i++){
        int cnt = food[i]/2;
        while(cnt--){
            temp += to_string(i);
        }
    }
    string temp2 = temp;
    reverse(temp2.begin(),temp2.end());
    temp += '0';
    answer = temp + temp2;
    return answer;
}