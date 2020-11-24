#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int num; cin >> num;
    
    // bruteforce last digit starting base 4

    int base = 4;
    while (true)
    {
        if (num % base == 3)
        {
            cout << base << "\n";
            return 0;
        }
        base++;
    }


    return 0;
}
