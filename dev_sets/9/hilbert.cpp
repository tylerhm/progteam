#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

queue<pair<pair<double, double>, int>> hilbertSort(queue<pair<pair<double, double>, int>> q, double s)
{
    if (q.empty() || q.size() == 1)
        return q;

    queue<pair<pair<double, double>, int>> sw, nw, ne, se;

    while (!q.empty())
    {
        pair<pair<double, double>, int> p = q.front();
        if (p.first.first < s / 2 && p.first.second < s / 2)
            sw.push(make_pair(make_pair(p.first.second, p.first.first), p.second));
        else if (p.first.first < s / 2 && p.first.second > s / 2)
            nw.push(make_pair(make_pair(p.first.first, p.first.second - (s / 2)), p.second));
        else if (p.first.first > s / 2 && p.first.second > s / 2)
            ne.push(make_pair(make_pair(p.first.first - (s / 2), p.first.second - (s / 2)), p.second));
        else if (p.first.first > s / 2 && p.first.second < s / 2)
            se.push(make_pair(make_pair((s / 2) - p.first.second, s - p.first.first), p.second));
        q.pop();
    }

    sw = hilbertSort(sw, s / 2);
    nw = hilbertSort(nw, s / 2);
    ne = hilbertSort(ne, s / 2);
    se = hilbertSort(se, s / 2);

    queue<pair<pair<double, double>, int>> ans;
    while (!sw.empty())
    {
        pair<pair<double, double>, int> p = sw.front();
        ans.push(p);
        sw.pop();
    }
    while (!nw.empty())
    {
        pair<pair<double, double>, int> p = nw.front();
        ans.push(p);
        nw.pop();
    }
    while (!ne.empty())
    {
        pair<pair<double, double>, int> p = ne.front();
        ans.push(p);
        ne.pop();
    }
    while (!se.empty())
    {
        pair<pair<double, double>, int> p = se.front();
        ans.push(p);
        se.pop();
    }
    return ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int n; cin >> n;
    double s; cin >> s;
    queue<pair<pair<double, double>, int>> usq;
    vector<pair<int, int>> data(n);
    
    for (int i = 0; i < n; i++)
    {
        double x, y; cin >> x >> y;
        usq.push(make_pair(make_pair(x, y), i));
        data[i] = make_pair(x, y);
    }

    queue<pair<pair<double, double>, int>> sq = hilbertSort(usq, s);

    while (!sq.empty())
    {
        pair<pair<double, double>, int> p = sq.front();
        cout << data[p.second].first << " " << data[p.second].second << "\n";
        sq.pop();
    }

    return 0;
}
