#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int transform(char c){
   return min(c-'A', 'Z'-c+1);
}

int solution(string name) {
    int answer = 0;
    int len = name.size();
    
    int slide = len - 1;

    for(int i = 0; i < len; i++){
        if(name[i] != 'A') answer += transform(name[i]);
      
        int j = i + 1;
        while(j < len && name[j] == 'A') j++;
        int positive = 2 * i + len - j;
        int negative = 2 * (len - j) + i;
        slide = min(slide, min(positive, negative));
        cout<< i << ' ' << j << ' ' << slide << ' ' << positive << ' ' << negative << endl;
    }
    answer += slide;
    return answer;
}