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

    vector<int> data(100);
    for (int i = 1; i <= CASES; i++)
		data[i-1] = i;
    
    shuffle(all(data), default_random_engine(0));

	FILE *out = fopen("house.in", "w");
	fprintf(out, "%d\n", CASES);
    for (int i : data)
        fprintf(out, "%d\n", i);
	

    return 0;
}
