#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    while (n--)
    {
        cin >> x;
        cout << x << " is ";
        if (x % 2 == 0)
            cout << "even";
        else
            cout << "odd";
        cout << endl;
    }

    return 0;
}
