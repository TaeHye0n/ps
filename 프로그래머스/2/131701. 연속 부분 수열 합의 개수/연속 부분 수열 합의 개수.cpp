#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> s;
    int n = elements.size();
    for (int i = 0; i < n; i++) {
        elements.push_back(elements[i]);
    }

        
    for (int i = 0; i < n; i++) {
        int len  = 1;
        int sum = elements[i];
        s.insert(sum);
        for (int j = i + 1; j < elements.size(); j++) {
            if (len >= n) break;
            sum += elements[j];
            s.insert(sum);
            len++;
        }
    }
    
    return s.size();
}