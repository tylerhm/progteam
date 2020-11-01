#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

char FILL_CHAR = 'f';
char FREE_CHAR = '-';
char END_CHAR = '~';

int r, c;

vector<vector<pair<char, int>>> maze;
queue<pair<int, int>> q;

bool safe(int row, int col) {
    return (row >= 0 && row < r && col >= 0 && col < c && (maze[row][col].first == FREE_CHAR || maze[row][col].first == END_CHAR));
}

void printMaze() {
    cout << "\n";
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            cout << maze[i][j].first;
        }
        cout << "\n";
    }
}

vector<int> dr = {0, -1, 0, 1};
vector<int> dc = {-1, 0, 1, 0};

int bfs() {
    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();
        int ro = f.first;
        int co = f.second;

        for (int i = 0; i < 4; i++) {
            int newRow = ro+dr[i];
            int newCol = co+dc[i];
            if (safe(newRow, newCol)) {
                q.push(make_pair(newRow, newCol));
                maze[newRow][newCol].second = maze[ro][co].second+1;
                if (maze[newRow][newCol].first == END_CHAR) return maze[newRow][newCol].second;
                maze[newRow][newCol].first = FILL_CHAR;
            }
        }

        //printMaze();
    }
    return -1;
}

int main()
{
    int n_cases; cin >> n_cases;
    while (n_cases--) {
        cin >> r >> c;
        maze = vector<vector<pair<char, int>>>(r, vector<pair<char, int>>(c, make_pair(' ', oo)));
        q = queue<pair<int, int>>();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                char c; cin >> c;
                maze[i][j].first = c;
                if (c == 'S') {
                    q.push(make_pair(i, j));
                    maze[i][j].second = 0;
                }
            }
        }
        cout << bfs() << "\n";
    }

    return 0;
}
