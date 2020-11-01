#include <bits/stdc++.h>
using namespace std;

int main()
{
	int np; cin >> np;
	while(np--)
	{
		int b, k; cin >> b >> k;

		// vector<vector<bool>> bags(b, vector<bool>(32, false));
		vector<int> bags(b, 0);
		for (int i = 0; i < b; i++)
		{
			int m; cin >> m;
			while(m--)
			{
				int candy; cin >> candy;
				bags[i] |= 1 << candy;
			}
		}

		int ans = 0;
		for (int mask = 0; mask < 1 << b; mask++)
		{
			int curAns = 0, bits = 0;
			for (int bit = 0; bit < b; bit++)
				if ((mask & (1 << bit))) bits++;
			if (bits != k) continue;

			int total = 0;
			for (int bit = 0; bit < b; bit++)
			{
				if ((mask & (1 << bit)) == 0) continue;
				total |= bags[bit];
			}

			for (int bit = 0; bit < 32; bit++)
				if ((total & (1 << bit))) curAns++;

			ans = max(ans, curAns);
		}

		cout << ans << "\n";
	}

	return 0;
}
