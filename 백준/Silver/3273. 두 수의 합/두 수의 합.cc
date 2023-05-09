/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, x;
    cin >> n;
    vector<int> nums;
    
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    cin >> x;
    
    sort(nums.begin(), nums.end());
    
    int l = 0;
    int r = n-1;
    int ans = 0;
    while(l < r){
        int temp = nums[l] + nums[r];
        if(temp == x) ans++; 
        if(temp >= x) r--;
        else l++;
    }
    
    cout << ans;
    return 0;
}