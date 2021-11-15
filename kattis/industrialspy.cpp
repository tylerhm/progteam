#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

bool * primes;
int numPrime;

void sieve(int n)
{
    primes = new bool[n];
    for (int i = 2; i < n; i++)
        primes[i] = true;

    for (int i = 2; i < sqrt(n); i++)
        if (primes[i] == true)
            for (int j = 2 * i; j < n; j += i)
                primes[j] = false;
}

bool shouldSwap(char str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void checkPerms(char str[], int index, int n)
{
    if (index >= n)
    {
        if (primes[atoi(str)])
            numPrime++;
        return;
    }

    for (int i = index; i < n; i++)
    {
        bool check = shouldSwap(str, index, i);
        if (check)
        {
            swap(str[index], str[i]);
            checkPerms(str, index + 1, n);
            swap(str[index], str[i]);
        }
    }
}

int main()
{
    int c;
    cin >> c;

    sieve(9999999);

    char * val;
    int len;
    while (c--)
    {
        cin >> val;
        len = strlen(val);
        numPrime = 0;
        checkPerms(val, 0, len);
        cout << numPrime << endl;
    }

    return 0;
}
