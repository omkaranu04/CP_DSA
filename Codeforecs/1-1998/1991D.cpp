#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << "1\n";
            cout << "1\n";
        }
        else if (n == 2)
        {
            cout << "2\n";
            cout << "1 2\n";
        }
        else if (n == 3)
        {
            cout << "2\n";
            cout << "1 2 2\n";
        }
        else if (n == 4)
        {
            cout << "3\n";
            cout << "1 2 2 3\n";
        }
        else if (n == 5)
        {
            cout << "3\n";
            cout << "1 2 2 3 3\n";
        }
        else if (n == 6)
        {
            cout << "4\n";
            cout << "1 2 2 3 3 4\n";
        }
        else
        {
            cout << "4\n";
            for (int i = 1; i <= n; i++)
            {
                cout << (i % 4) + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}