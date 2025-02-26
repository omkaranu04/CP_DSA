#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bool possible = false;
    int index = -1;

    for (int i = 0; i < n; i++)
    {
        bool valid = false;
        for (int j = 0; j < n; j++)
        {
            if (i != j && abs(a[i] - a[j]) % k == 0)
            {
                valid = true;
                break;
            }
        }
        if (!valid)
        {
            possible = true;
            index = i + 1;
            break;
        }
    }

    if (possible)
    {
        cout << "YES" << endl;
        cout << index << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}