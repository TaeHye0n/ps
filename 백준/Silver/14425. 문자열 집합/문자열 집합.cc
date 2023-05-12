#include <iostream>
#include <map>

using namespace std;
map<string, bool> m;
int N, M;
string str;
int res = 0;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		m.insert({str,true});
	}

	for (int i = 0; i < M; i++)
	{
		cin >> str;
		if (m[str])
			res++;
	}
	cout << res;

}