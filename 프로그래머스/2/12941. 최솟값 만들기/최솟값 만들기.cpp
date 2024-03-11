#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    return inner_product(A.begin(), A.end(), B.begin(), 0);
}