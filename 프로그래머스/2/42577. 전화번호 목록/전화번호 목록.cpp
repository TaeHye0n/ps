#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> m;
    
    for (auto s : phone_book) {
        m[s] = 1;
    }
    
    for (int i = 0; i < phone_book.size(); i++) {
        for (int j = 0; j < phone_book[i].size(); j++) {
            string temp = phone_book[i].substr(0, j);
            if (m[temp]) return false;
        }
    }
    return answer;
}