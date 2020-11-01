#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
int oo = -1^1<<31;
using namespace std;

int main()
{
	int n; cin >> n;
	string g;

	int k, min, max;
	double median;
	vector<int> s;

	for (int i = 0; i < n; i++)
	{
		int k; cin >> k;
		s = vector<int>(k);

		for (int j = 0; j < k; j++) cin >> g >> s[j];
		sort(s);
		min = s[0];
		max = s[s.size() - 1];

		if (s.size() % 2 == 1)
			median = s[s.size() / 2];
		else
			median = (double)(s[s.size() / 2] + s[s.size() / 2 - 1]) / 2;

		cout << "Case #" << i + 1 << ": " << max << " " << min << " " << median << " " << "\n";
	}

    return 0;
}
