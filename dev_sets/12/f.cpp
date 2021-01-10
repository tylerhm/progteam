#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
#define nl '\n'
int oo = -1^1<<31;
using namespace std;

void addOne(vector<int> &number, int index) {
    number[index]++;
    if (number[index] >= 10) {
        number[index] = 0;
        addOne(number, index-1);
    }
}

int calcVal(vector<int> &number) {
    int ret = 0;
    int mult = pow(10, number.size()-1);
    for (int dig : number) {
        ret += dig * mult;
        mult /= 10;
    }
    return ret;
}

void solve(string n) {
    vector<int> number(n.size());
    for (int i = 0; i < n.size(); i++)
        number[i] = n[i]-'0';

    //for (int i = 0; i < number.size(); i++) cout << number[i] << ' ';
    //cout << nl;

    int orig = calcVal(number);

    for (int i = 0; i < n.size()/2; i++)
        while (number[i] != number[number.size()-1-i])
            addOne(number, number.size()-1-i);

    //for (int i = 0; i < number.size(); i++) cout << number[i] << ' ';
    //cout << nl;

    int other = calcVal(number);
    cout << other - orig << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string n; cin >> n;
    while (n != "0") {
        solve(n);
        cin >> n;
    }

    return 0;
}
