#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int temp, negCount = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp < 0)
            negCount++;
    }
    cout << negCount << endl;

    return 0;
}
