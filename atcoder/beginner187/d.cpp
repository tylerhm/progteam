#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

struct city {
    ll a, b;
    city(int a, int b) : a(a), b(b) {}
    bool operator<(city other) {
        return (2*a+b)>(2*other.a+other.b);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<city> voters(n, city(0,0));
    ll aV = 0, bV = 0;
    for (int i = 0; i < n; i++) {
        ll a, b; cin >> a >> b;
        voters[i].a = a;
        voters[i].b = b;
        aV += a;
    }

    sort(all(voters));

    int index = 0;
    while (bV <= aV) {
        aV -= voters[index].a;
        bV += voters[index].a + voters[index].b;
        index++;
    }

    //cout << aV << " " << bV << nl;
    cout << index << nl;

    return 0;
}
