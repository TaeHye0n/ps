#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    set<string> set;
    int len = words.size();
    
    char back = ' ';
    for (int i = 0; i < len; i++) {
        string s = words[i];
        if ((set.find(s) != set.end() || s[0] != back) && i != 0) {
            answer[1] = i / n + 1;
            answer[0] = i % n + 1;
            break;
        }
        set.insert(s);
        back = s[s.length()-1];
    }
    

    return answer;
}