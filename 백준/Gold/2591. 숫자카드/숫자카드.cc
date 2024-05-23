#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
 
using namespace std;
 
int dp[100];
 
int main() 
{
    string str;
    cin >> str;
 
    dp[0] = 1;
    for (int i = 1; i <  str.size(); i++) 
    {
        if (((str[i] - '0') + (str[i - 1] - '0') * 10) <= 34 && str[i - 1] != '0') 
        {
            if (i == 1) 
                dp[i] = 1;
            else 
                dp[i] = dp[i - 2];
        }
        if (str[i] != '0')
            dp[i] += dp[i - 1];
    }
    printf("%d", dp[str.size() - 1]);
}