#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 0;
    int k = 0;
    int tmp = 0;
    int m = *max_element(citations.begin(), citations.end());
    vector<int> v;
    if( m == 0) m += 1;
    while(k != m){
        int cnt = 0;
        int cnt_2 = 0;
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] >= k) cnt++;
            else cnt_2++;
        }
        if(cnt >= k && cnt_2 <= k) v.push_back(k);  
       
        k++;  
    }
    sort(v.begin(), v.end(), cmp);
    answer = v.front();
    return answer;
}

/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;

    std::sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        if (citations.size() - i <= citations[i]) {
            answer = citations.size() - i;
            break;
        }
    }


    return answer;
}*/