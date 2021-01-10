#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

struct vec
{
    int x, y;

    vec(int x, int y) : x(x), y(y) {}
    vec() : x(0), y(0) {}

    void move(vec d)
    {
        x += d.x;
        y += d.y;
    }

    bool isZero()
    {
        return x == 500 && y == 500;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    vector<vec> data = vector<vec>(n, vec());

    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        data[i].x = x;
        data[i].y = y;
    }

    unordered_map<pair<int, int>, int, pair_hash> prevVec;
    int ans = 0;
    vec curVec = vec(500, 500);

    for (int i = 0; i < n; i++)
    {
        curVec.move(data[i]);

        cout << curVec.x << " " << curVec.y << endl;

        if (curVec.isZero())
            ans++;
        
        pair<int, int> paired = make_pair(curVec.x - 500, curVec.y - 500);
        if (prevVec.find(paired) != prevVec.end())
            ans += (prevVec[paired]);

        prevVec[paired]++;
    }

    cout << ans << endl;

    return 0;
}
