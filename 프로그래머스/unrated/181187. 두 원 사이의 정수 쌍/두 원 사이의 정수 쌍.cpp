#include <string>
#include <vector>
#include <cmath>
#include <iostream>

typedef long long ll;
using namespace std;

ll solution(int r1, int r2) {
    ll answer = 0;
    ll maxY = 0, minY = 0;
    for(int i = 1; i <= r2; i++){
        ll squareR2 = (ll)r2*r2;
        ll squareI = (ll) i*i;
        ll squareR1 = (ll)r1*r1;
        maxY = floor(sqrt(squareR2 - squareI)); 
        if(i >= r1) minY = 0; 
        else minY = ceil(sqrt(squareR1 - squareI));
        // cout << maxY << " " << minY << endl;
        answer += maxY-minY+1;
    }
    return answer*4;
}