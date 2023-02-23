#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int len1 = cards1.size();
    int len2 = cards2.size();
    
    int idx1 = 0;
    int idx2 = 0;
    
    for(string s : goal){
        if(idx1 < len1 && cards1[idx1] == s) idx1++;
        else if (idx2 < len2 && cards2[idx2] == s) idx2++;
        else return "No";
    }
    return answer;
}