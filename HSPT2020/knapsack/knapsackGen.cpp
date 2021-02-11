#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define CASES 100

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	FILE *out = fopen("knapsack.in", "w");
	fprintf(out, "%d\n", CASES);
	for (int i = 0; i < CASES; i++) {
		int n = (rand()%1000)+1;
		int m = (rand()%1001)+999000;
		fprintf(out, "%d %d\n", n, m);
		for (int i = 0; i < n; i++)
			fprintf(out, "%d %d\n", (rand()%1000000)+1, (rand()%1050)+1);
	}

    return 0;
}
