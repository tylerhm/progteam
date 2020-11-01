#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
int oo = -1^1<<31;
using namespace std;

int main()
{
	int n; cin >> n;

	vector<vector<int>> adjMatrix = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> adjMatrix[i][j];

	int t; cin >> t;
	int dis;
	string walk;
	while (t--)
	{
		dis = 0;
		cin >> walk;
		for (int i = 1; i < walk.length(); i++)
			dis += adjMatrix[walk.at(i-1)-'A'][walk.at(i)-'A'];
		cout << dis << "\n";
	}
    return 0;
}
