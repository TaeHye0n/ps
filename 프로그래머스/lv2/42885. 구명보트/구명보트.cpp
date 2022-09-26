#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int first = 0, last = people.size()-1;
    
    while(first <= last){
        if(people[first] + people[last] <= limit){
            first++;
            last--;
        }
        else last--;
        answer++;
    }
    return answer;
}