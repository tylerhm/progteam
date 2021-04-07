#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define CASES 5
#define SPECIAL 3

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	FILE *out = fopen("knapsack.in", "w");
	fprintf(out, "%d\n", CASES+SPECIAL);

	// Special One.
	fprintf(out, "1000 995000\n");
    for (int i = 0; i < 1000; i++)
		fprintf(out, "1 1050\n");

	// Special Two, anti max val greedy
	fprintf(out, "1000 1000000\n");
	for (int i = 0; i < 750; i++)
		fprintf(out, "10000 1050\n");
	for (int i = 0; i < 250; i++)
		fprintf(out, "9999 950\n");	

	// Special Three, anti min weight greedy
	fprintf(out, "1000 1000000\n");
	for (int i = 0; i < 750; i++)
		fprintf(out, "10000 1050\n");
	for (int i = 0; i < 250; i++)
		fprintf(out, "1 950\n");	

	// Random need DP
	for (int i = 0; i < CASES - 1; i++) {
		int n = 1000;
		int m = 1000000;
		fprintf(out, "%d %d\n", n, m);
		for (int i = 0; i < n; i++)
			fprintf(out, "%d %d\n", (rand()%1000000)+1, 1000+(rand()%50));
	}

	// Random no DP
	int n = (rand()%1000)+1;
	int m = (rand()%1001)+999000;
	fprintf(out, "%d %d\n", n, m);
	for (int i = 0; i < n; i++)
		fprintf(out, "%d %d\n", (rand()%1000000)+1, (rand()%1050)+1);

    return 0;
}
