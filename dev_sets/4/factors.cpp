#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int countPrimeFactors(int n)
{
    int count = 0;
    if (n % 2 == 0) count++;
    while (n % 2 == 0) n /= 2;
    for (int i = 3; i <= sqrt(n); i = i+2) {
        if (n % i == 0) count++;
        while (n % i == 0) n /= i;
    }
    if (n > 2)
        count++;
    return count;
}

int countFactors(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (!(n % i))
            count++;
    return count;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int d; cin >> d;
        ll counter = d;
        while (counter < 10e15) {
            int pFactors = countPrimeFactors(counter);
            if (pFactors <= 2) {
                int factors = countFactors(counter);
                if (factors == d) {
                    cout << counter << "\n";
                    break;
                }
            }
            counter++;
        }
    }
    return 0;
}
