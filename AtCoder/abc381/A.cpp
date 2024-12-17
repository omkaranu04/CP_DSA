#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll c1 = 0, c2 = 0, c3 = 0;
    for (auto i : s)
    {
        if (i == '1')
        {
            if (c2 != 0)
            {
                cout << "No\n";
                return 0;
            }
            c1++;
        }
        else if (i == '2')
        {
            c2++;
        }
        else if (i == '/')
        {
            c3++;
        }
    }
    if (c3 == 1 && (c1 == c2) && (c1 == n / 2))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}