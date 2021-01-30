#include <bits/stdc++.h>
#define all(a) begin(a), end(a)
#define nl '\n'
typedef long long int ll;
int oo = -1^1<<31;
using namespace std;

bool on(int mask, int bit) { return mask&(1<<bit); }

int main()
{
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int switches; cin >> switches;
    int hibit = (int)log2(switches);
    vector<int> answer(switches, 0);
    for(int curBit = 0; curBit <= hibit; curBit++)
    {
    	cout << "ASK ";
    	vector<int> query;
    	for(int mask = 1; mask <= switches; mask++)
    		if(on(mask, curBit))
    			query.push_back(mask);

    	cout << query.size() << ' ';
    	for(int j = 0; j < query.size(); j++)
    		cout << query[j] << ' ';
    	cout << endl;

    	for(int j = 0; j < query.size(); j++)
    	{
    		int response; cin >> response;
    		answer[response-1] += pow(2, curBit);
    	}
    }

    cout << "ANSWER ";
    for(int i = 0; i < answer.size(); i++)
    	cout << answer[i] << ' ';
    cout << endl;

    return 0;
}
