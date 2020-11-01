#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

const int MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vector<int> primeSieve(int lim) {
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (int i = 4; i < lim; i += 2) isprime[i] = 0;
    for (int i = 3; i * i < lim; i += 2)
        if (isprime[i])
            for (int j = i * i; j < lim; j += i * 2) isprime[j] = 0;
    vector<int> pr;
    for (int i = 2; i < lim; i++)
        if (isprime[i]) pr.push_back(i);
    return pr;
}

int main()
{
    vector<int> primes = primeSieve(10000);
    primes.insert(primes.begin(), 1, 1);
    int n_cases; cin >> n_cases;
    while (n_cases--)
    {
        int n, c; cin >> n >> c;
        cout << n << ": ";

        // search for n first
        int highSide;
        for (int i = 0; i < primes.size(); i++)
        {
            if (primes[i] == n || primes[i] > n)
            {
                if (primes[i] == n)
                    highSide = i;
                if (primes[i] > n)
                    highSide = i-1;
                break;
            }
        }        
        int totalPrint = c*2;
        if ((highSide+1) % 2 == 1)
            totalPrint--;

        int leftOut = (highSide+1) - totalPrint;
        int start = (leftOut/2);
        int end = start+totalPrint;
        for (int i = (start > 0)? start: 0; i <= highSide && i < end; i++)
            cout << primes[i] << " ";

        cout << "\n\n";
    }
    return 0;
}
