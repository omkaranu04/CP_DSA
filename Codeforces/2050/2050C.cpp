#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin >> s;

    ll sum = 0, count2 = 0, count3 = 0;
    for (char c : s)
    {
        int digit = c - '0';
        sum += digit;
        if (digit == 2)
            count2++;
        if (digit == 3)
            count3++;
    }

    if (sum % 9 == 0 || count3 == s.length())
    {
        cout << "YES" << endl;
        return;
    }

    for (int x = 0; x <= count2; x++)
    {
        for (int y = 0; y <= count3; y++)
        {
            ll current_sum = sum + x * 2 + y * 6;
            if (current_sum % 9 == 0)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
