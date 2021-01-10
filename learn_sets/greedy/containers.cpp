#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

struct st {
    vector<pair<char, int>> order;
    char top() {
        return order[order.size()-1].first;
    }
    void push() {
        order[order.size()-1].second++;
    }
    void push(char c) {
        order.emplace_back(c, 1);
    }
    bool contains(char c) {
        for (auto e : order)
            if (e.first == c)
                return true;
    }
};

void printStacks(vector<st> stacks) {
    cout << "Stacks:\n";
    for (st sta : stacks) {
        for (auto e : sta.order)
            cout << e.first << " ";
        cout << "\n";
    }
    cout << "\n\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    string inp; cin >> inp;
    while (inp != "end") {
        vector<st> stacks;
        for (char c : inp) {

            printStacks(stacks);

            // look for A A A placements
            bool foundStack = false;
            for (int i = 0; i < stacks.size(); i++)
                if (stacks[i].top() == c) {
                    stacks[i].push();
                    foundStack = true;
                    break;
                }
            if (foundStack) continue;

            // look for B B A placements
            for (int i = 0; i < stacks.size(); i++)
                if (stacks[i].top() > c) {
                    stacks[i].push(c);
                    foundStack = true;
                    break;
                }
            if (foundStack) continue;

            // look for A A B <-- A placements.
            // attempt to relocate B
            // worst case make new stack for B
            for (int i = 0; i < stacks.size(); i++) {
                
            }

            if (!foundStack) stacks.emplace_back(c, c);
        }
        cout << stacks.size() << "\n";
        cin >> inp;
    }

    return 0;
}
