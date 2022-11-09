#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    v.push_back(0);
    int i = 0;
    while(1){
        int size = ingredient.size();
        if(i+3 >= size) break;
        if(ingredient[i] == 1 && ingredient[i+1] == 2 && ingredient[i+2] == 3 && ingredient[i+3] == 1){
            answer++;
            ingredient.erase(ingredient.begin()+i, ingredient.begin()+i+4);
            i = v.back();
            v.pop_back();
        }
        else if(ingredient[i] == 1){
            v.push_back(i);
            i++;
        }
        else i++;
    }
    return answer;
}