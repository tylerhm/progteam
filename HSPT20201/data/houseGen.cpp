#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

#define CASES 100000

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	FILE *out = fopen("house.in", "w");
	fprintf(out, "%d\n", CASES);
	for (int i = 0; i < CASES; i++)
		fprintf(out, "%d\n", (rand()%100)+1);

    return 0;
}
