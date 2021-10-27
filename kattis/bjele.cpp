#include <iostream>

using namespace std;

int main()
{
    int actual[6] = {1, 1, 2, 2, 2, 8};
    int c;
    for (int i = 0; i < 6; i++)
    {
        cin >> c;
        cout << actual[i] - c << " ";
    }

    return 0;
}
