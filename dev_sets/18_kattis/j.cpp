#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct faucet {
  ll t, a, b;
};

bool operator<(const faucet &a, const faucet &b) {
  return a.t < b.t;
}

int n;
vector<faucet> f, fbac;

bool getMinTemp(int flow, double *temp) {
  // turn all flows down
  int flowSum = 0;
  vector<ll> flows(n);
  rep(i, 0, n) {
    flowSum += f[i].a;
    flows[i] = f[i].a;
  }

  // if the flow isn't possible then stop
  if (flowSum > flow) return false;

  // fill cold faucets first
  int index = 0;
  while (flowSum < flow) {

    // we don't have enough flow!
    if (index == n) return false;

    int neededFlow = flow - flowSum;
    int availableFlow = f[index].b - flows[index];

    if (availableFlow <= neededFlow) {
      flowSum += availableFlow;
      flows[index] = f[index].b;
    }
    else {
      flowSum += neededFlow;
      flows[index] += neededFlow;
    }

    index++;
  }

  // a + b + c
  // ---------
  //    f

  // a/f + b/f + c/f

  ll numerator = 0;
  rep(i, 0, n) numerator += flows[i]*f[i].t;
  *temp = numerator / (double)flow;
  return true;
}

bool getMaxTemp(int flow, double *temp) {
  // turn all flows down
  int flowSum = 0;
  vector<ll> flows(n);
  rep(i, 0, n) {
    flowSum += fbac[i].a;
    flows[i] = fbac[i].a;
  }

  // if the flow isn't possible then stop
  if (flowSum > flow) return false;

  // fill hot faucets first
  int index = 0;
  while (flowSum < flow) {

    // we don't have enough flow!
    if (index == n) return false;

    int neededFlow = flow - flowSum;
    int availableFlow = fbac[index].b - fbac[index].a;

    if (availableFlow <= neededFlow) {
      flowSum += availableFlow;
      flows[index] = fbac[index].b;
    }
    else {
      flowSum += neededFlow;
      flows[index] += neededFlow;
    }
    index++;
  }

  ll numerator = 0;
  rep(i, 0, n) numerator += flows[i]*fbac[i].t;
  *temp = numerator / (double)flow;
  return true;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  cin >> n;
  f = vector<faucet>(n);
  rep(i, 0, n) {
    int ti, ai, bi; cin >> ti >> ai >> bi;
    f[i] = faucet {ti, ai, bi};
  }

  sort(all(f));
  fbac = f;
  reverse(all(fbac));

  int r; cin >> r;
  while (r --> 0) {
    int temp, flow; cin >> temp >> flow;

    double minTemp, maxTemp;
    if (!getMinTemp(flow, &minTemp) || !getMaxTemp(flow, &maxTemp)) {
      cout << "no" << '\n';
      continue;
    }

    cout << minTemp << ' ' << maxTemp << '\n';
    cout << temp << '\n';
    cout << ((minTemp <= temp && temp <= maxTemp)? "yes" : "no") << '\n';
  }
}