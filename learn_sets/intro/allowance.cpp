#include <bits/stdc++.h>
#define ll long long int
int oo = -1^1<<31;
using namespace std;

int downPow2(int n)
{
	n = n + 1;
	while (n & n - 1)
		n = n & n - 1;

	return n;
}

int main()
{
	int w; cin >> w;

	int n, des;
	while (w--)
	{
		cin >> n;
		des = downPow2(n) - 1;
		cout << (int)log2(des)+1 << " " << des << "\n";
	}
    return 0;
}
