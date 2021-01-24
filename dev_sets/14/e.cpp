#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

template <typename T>
struct Q {
  T a, b;
  Q(T p, T q = 1) {
    T g = gcd(p, q);
    a = p / g;
    b = q / g;
    if (b < 0) a = -a, b = -b;
  }
  T gcd(T x, T y) const { return __gcd(x, y); }
  Q operator+(const Q& o) const {
    return {a * o.b + o.a * b, b * o.b};
  }
  Q operator-(const Q& o) const {
    return *this + Q(-o.a, o.b);
  }
  Q operator*(const Q& o) const { return {a * o.a, b * o.b}; }
  Q operator/(const Q& o) const { return *this * Q(o.b, o.a); }
  Q recip() const { return {b, a}; }
  int signum() const { return (a > 0) - (a < 0); }
  bool operator<(const Q& o) const {
    return a * o.b < o.a * b;
  }
  friend ostream& operator<<(ostream& cout, const Q& o) {
    return cout << o.a << "/" << o.b;
  }
};



void solve(int t) {

}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    

    return 0;
}
