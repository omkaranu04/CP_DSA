#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> latin;
        for (int i = 0; i < 3; i++)
        {
            string a;
            cin >> a;
            latin.push_back(a);
        }
        vector<int> a(3, 0);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (latin[i][j] == 'A')
                    a[0]++;
                if (latin[i][j] == 'B')
                    a[1]++;
                if (latin[i][j] == 'C')
                    a[2]++;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            if (a[i] == 2)
                cout << (char)(i + 'A') << endl;
        }
    }
    return 0;
}