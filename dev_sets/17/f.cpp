#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

int lps(vector<int> data) 
{ 
   int n = data.size(); 
   int i, j, cl; 
   int L[n][n];  // Create a table to store results of subproblems 
  
  
   // Strings of length 1 are palindrome of lentgh 1 
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    for (cl=2; cl<=n; cl++) 
    { 
        for (i=0; i<n-cl+1; i++) 
        { 
            j = i+cl-1; 
            if (data[i] == data[j] && cl == 2) 
               L[i][j] = 2; 
            else if (data[i] == data[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
} 

void solve(int n) {
    vector<int> vals(n);
    for (auto &v : vals) cin >> v;

    cout << lps(vals)/2 << nl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n;
    while (true) {
        try {
            cin >> n;
            solve(n);
        }
        catch (...) {
            return 0;
        }
    }
    return 0;
}
