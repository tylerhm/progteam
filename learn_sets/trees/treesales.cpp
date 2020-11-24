#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

template <typename T>
struct BIT {
    vector<T> s;
    int n;
    BIT(int n) : s(n + 1, 0), n(n) {}
    void update(int i, T v) {
        for (i++; i <= n; i += i & -i) s[i] += v;
    }
    T query(int i) {
        T ans = 0;
        for (i++; i; i -= i & -i) ans += s[i];
        return ans;
    }
    T query(int l, int r) { return query(r) - query(l - 1); }
};

struct node
{
    string name;
    int combinedSales;
    unordered_map<string, node*> children;

    node(string n) : name(n), combinedSales(0), children(unordered_map<string, node*>()) {}
};

struct BITAction
{
    bool query;
    string name;
    int amount;

    BITAction(bool q, string n, int am) : query(q), name(n), amount(am) {}
};

node *ceo;
vector<BITAction> actions;
vector<int> preorder, postorder;
unordered_map<string, int> nameToIndex;
int order;

void createEmployee(string boss, node *emp)
{
    queue<node*> bfs = queue<node *>();
    node *curEmp;
    bfs.push(ceo);
    while (true)
    {
        curEmp = bfs.front();
        bfs.pop();
        for (auto entry : curEmp->children)
        {
            if (entry.first == boss)
            {
                entry.second->children[emp->name] = emp;
                return;
            }
            else
                bfs.push(entry.second);
        }
    }
}

void prepost(node *curEmp)
{   
    order++;
    preorder[nameToIndex[curEmp->name]] = order;
    for (auto entry : curEmp->children)
        prepost(entry.second);
    postorder[nameToIndex[curEmp->name]] = order;
}

int main()
{
    ceo = NULL;
    int n_cases; cin >> n_cases;
    int iter = 1;
    while (n_cases--)
    {
        cout << "COMPANY " << iter++ << "\n";
        int n; cin >> n;
        actions = vector<BITAction>();
        nameToIndex = unordered_map<string, int>();
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            string command, param1; cin >> command >> param1;
            if (command == "ADD")
            {
                string param2; cin >> param2;
                if (param1 == "ROOT")
                {
                    ceo = new node(param2);
                    nameToIndex[param2] = index++;
                }
                else
                {
                    node *emp = new node(param2);
                    nameToIndex[param2] = index++;
                    if (ceo->name == param1)
                        ceo->children[param2] = emp;
                    else
                        createEmployee(param1, emp);
                }
            }
            else if (command == "SALE")
            {
                int param2; cin >> param2;
                actions.emplace_back(false, param1, param2);
            }
            else // query
                actions.emplace_back(true, param1, 0);
        }
        order = -1;
        preorder = vector<int>(nameToIndex.size());
        postorder = vector<int>(nameToIndex.size());
        prepost(ceo);

        BIT<int> bit = BIT<int>(nameToIndex.size());

        for (BITAction a : actions)
        {
            if (!a.query)
                bit.update(preorder[nameToIndex[a.name]], a.amount);
            else
            {
                int index = nameToIndex[a.name];
                int start = preorder[index];
                int end = postorder[index];
                cout << bit.query(start, end) << "\n";
            }
        }
    }
    return 0;
}
