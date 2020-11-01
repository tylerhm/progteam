#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

vector<bool> used;
vector<int> vals;
vector<long double> perm;

bool applyOperation(long double& value1, long double& value2, int& iteration) {
    switch (iteration % 4) {
        case 0:
            value1 += value2;
            break;
        case 1:
            value1 -= value2;
            break;
        case 2:
            value1 *= value2;
            break;
        case 3:
            if (value2 == 0) return false;
            value1 /= value2;
            break;
    }
    if (value1 != floor(value1)) return false;
    return true;
}

bool permute(int p, vector<bool>& used, vector<long double>& perm) {
    if (p == vals.size()) {
        long double res = perm[0];
        for (int i = 0; i < vals.size()-1; i++) {
            if (!applyOperation(res, perm[i+1], i)) return false;
        }
        return true;
    }
    for (int i = 0; i < vals.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            perm[p] = vals[i];
            if (permute(p + 1, used, perm))
                return true;
            used[i] = false;
        }
    }
    return false;
}

int main()
{
    int n_cases; cin >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        cout << "Set " << iter++ << " is a ";
        int k; cin >> k;
        vals = vector<int>(k);
        used = vector<bool>(k, false);
        perm = vector<long double>(k);
        for (int i = 0; i < k; i++) cin >> vals[i];
        if (permute(0, used, perm))
            cout << "Happy Set =)\n";
        else
            cout << "Sad Set =(\n";
    }
    return 0;
}
