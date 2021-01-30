#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

set<vector<int>> ans;

void pop_front(vector<int>& vec) {
    assert(!vec.empty());
    vec.erase(vec.begin());
}

void goEven(vector<int> cur) {
    if (cur.size() == 2) {
        ans.insert(vector<int>(1, cur[0]+cur[1]));
        return;
    }
    int front = cur[0];
    pop_front(cur);
    cur.pop_back();

    int m1 = cur.size()/2;
    int m2 = cur.size()/2+1;
    cur[m1] += front;
    cur[m2] += front;
    ans.insert(cur);
    goEven(cur);
    cur[m1] -= front;
    cur[m2] -= front;
    for (int i = 1; i <= m1; i++) {
        if (cur[m1-i] + front > cur[m1-i+1]) continue;
        cur[m1-i] += front;
        cur[m2+i] += front;
        if (ans.insert(cur).second);
            goEven(cur);
        cur[m1-i] -= front;
        cur[m2+i] -= front;
    }
}

void goOdd(vector<int> cur) {
    if (cur.size() == 1) return;
    int front = cur[0];
    pop_front(cur);
    cur.pop_back();

    int m = cur.size()/2;
    cur[m] += front*2;
    ans.insert(cur);
    goOdd(cur);
    cur[m] -= front*2;
    for (int i = 1; i <= m; i++) {
        if (cur[m-i] + front > cur[m-i+1]) continue;
        cur[m+i] += front;
        cur[m-i] += front;
        if (ans.insert(cur).second);
            goOdd(cur);
        cur[m+i] -= front;
        cur[m-i] -= front;
    }
}

int solve(int n) {
    vector<int> start(n, 1);
    ans.clear();
    ans.insert(start);
    if (n&1) goOdd(start);
    else goEven(start);
    return ans.size();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    for (int i = 1; i < 250; i++)
        cout << solve(i) << endl;

    return 0;
}
