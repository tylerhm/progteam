#include <bits/stdc++.h>
#define ll long long int
#define sort(a) sort(a.begin(), a.end());
#define fill(a, b) fill(a.begin(), a.end(), b);
int oo = -1^1<<31;
using namespace std;

struct Student {
  
  string name;
    vector<int> counts;

    Student(string _name)
    {
        name = _name;
        counts = vector<int>(26, 0);
        for (char c : name)
            counts[c-'A']++;
    }

    bool operator<(const Student& s) const
    {
        return s.counts < counts;
    }
};

int main()
{
    int n; cin >> n;
    
    vector<Student> students;
    for (int i = 0; i < n; i++)
    {
        int m; cin >> m;
        students.clear();
        string name;
        for (int j = 0; j < m; j++)
        {
            cin >> name;
            students.emplace_back(Student(name));
        }
        sort(students);

        cout << "Class #" << i+1 << " ordering" << "\n";
        for (Student s : students)
            cout << s.name << "\n";
        cout << "\n";
    }

    return 0;
}
