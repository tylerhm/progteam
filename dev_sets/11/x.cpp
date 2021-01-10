#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; getline(cin, inp);

    vector<int> freq(26);
    int length = 0;
    for (char c : inp) {
        if (c >= 65 && c <= 90)
            c += 32;

        if (!(c >= 97 && c <= 122))
            continue;

        freq[c-'a']++;
    }

    sort(all(freq));
    reverse(all(freq));

    int curIter = 0;
    int curIndex = 0;
    vector<pair<int, int>> lengthOptions;
    lengthOptions.emplace_back(1, 1);
    lengthOptions.emplace_back(3, 2);
    lengthOptions.emplace_back(5, 3);
    lengthOptions.emplace_back(7, 5);
    lengthOptions.emplace_back(9, 8);
    lengthOptions.emplace_back(11, 10000);

    for (int f : freq) {
        if (f == 0)
            break;
        
        if (curIter == lengthOptions[curIndex].second) {
            curIter = 0;
            curIndex++;
        }

        curIter++;
        length += f * (lengthOptions[curIndex].first + 3);
    }
    length -= 3;

    cout << length << endl;

    return 0;
}
