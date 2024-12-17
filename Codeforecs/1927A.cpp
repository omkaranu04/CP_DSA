#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll first = 0, last = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'B')
            {
                first = i;
                break;
            }
        }
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == 'B')
            {
                last = i;
                break;
            }
        }
        cout << last - first + 1 << endl;
    }
    return 0;
}