#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 0)
        {
            if (a > b)
                cout << "First" << endl;
            else if (b > a)
                cout << "Second" << endl;
            else if (a == b)
                cout << "Second" << endl;
        }
        else
        {
            if (a > b)
                cout << "First" << endl;
            else if (b > a)
                cout << "Second" << endl;
            else
            {
                if (c % 2 == 0)
                    cout << "Second" << endl;
                else
                    cout << "First" << endl;
            }
        }
    }
    return 0;
}