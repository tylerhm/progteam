#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

int main()
{
    int n_cases; cin >> n_cases;
    for (int c = 0; c < n_cases; c++)
    {
        int k; cin >> k;
        vector<string> names = vector<string>(k);
        for (int i = 0; i < k; i++) cin >> names[i];
        int m; cin >> m;
        cout << "List #" << c+1 << ":\n";
        while (m--)
        {
            string letters; cin >> letters;
            cout << letters << ": ";
            for (int ni = 0; ni < names.size(); ni++)
            {
                string name = names[ni];
                int mtchI = 0;
                bool found = false;
                for (int i = 0; i < name.length(); i++)
                {
                    if (name[i] == letters[mtchI])
                        mtchI++;
                    if (mtchI == letters.size())
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    cout << "FOUND" << "\n";
                    break;
                }
                else
                {
                    if (ni == names.size() - 1)
                        cout << "NOT FOUND" << "\n";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}
