#include <bits/stdc++.h>
#define ll long long int
#define all(a) begin(a), end(a)
int oo = -1^1<<31;
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void fillOrder(int v, bool visited[], stack<int> &s);
    void DFS(int v, bool visited[]);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void solve();
        Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

int currentSize;
int maxSize = INT_MIN;

void Graph::DFS(int v, bool visited[])
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
        {
            DFS(*i, visited);
            currentSize++;
        }
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
            g.adj[*i].push_back(v);
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::fillOrder(int v, bool visited[], stack<int> &s)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            fillOrder(*i, visited, s);

    s.push(v);
}

int totalGroupSize;

void Graph::solve()
{
    stack<int> s;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            fillOrder(i, visited, s);
    
    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    maxSize = INT_MIN;

    while (!s.empty())
    {
        int v = s.top();
        s.pop();

        if (!visited[v])
        {
            currentSize = 1;
            gr.DFS(v, visited);
            if (currentSize > maxSize)
                maxSize = currentSize;
        }
    }

    cout << (totalGroupSize - maxSize) << endl;
}

void tokenize(string const &str, vector<string> &out)
{
    size_t start;
    size_t end = 0;

    while ((start = str.find_first_not_of(" ", end)) != std::string::npos)
    {
        end = str.find(" ", start);
        out.push_back(str.substr(start, end - start));
    }
}

struct person 
{
    string name;
    string speak;
    vector<string> understand;

    person(string n, string s, vector<string> u) : name(n), speak(s), understand(u) {}
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    string garbage; getline(cin, garbage);
    
    unordered_map<string, int> nameToIndex;
    vector<person> people;
    
    for (int i = 0; i < n; i++)
    {
        string line; getline(cin, line);
        vector<string> data;
        tokenize(line, data);

        string name = data[0];
        string speak = data[1];

        nameToIndex[name] = nameToIndex.size();

        data.erase(data.begin(), data.begin()+1);
        people.emplace_back(name, speak, data);
    }

    Graph g(people.size());
    totalGroupSize = people.size();
    for (int i = 0; i < people.size(); i++)
    {
        for (int j = 0; j < people.size(); j++)
        {
            if (i == j)
                continue;

            for (string understands : people[j].understand)
            {
                if (people[i].speak == understands)
                    g.addEdge(nameToIndex[people[i].name], nameToIndex[people[j].name]);
            }
        }
    }

    g.solve();

    return 0;
}
