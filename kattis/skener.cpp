#include <iostream>

using namespace std;

int main()
{
    int r, c, zr, zc;
    cin >> r >> c >> zr >> zc;
    
    string article, bigger;
    for (int i = 0; i < r; i++)
    {
        cin >> article;
        for (int j = 0; j < article.size(); j++)
            for (int k = 0; k < zc; k++)
                bigger.push_back(article[j]);
        for (int j = 0; j < zr; j++)
            cout << bigger << endl;
        bigger.clear();
    }
        
    return 0;
}
