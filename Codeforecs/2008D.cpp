#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> F(n + 1);
    vector<bool> visited(n + 1, false);
    string s;

    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }

    cin >> s;
    s = " " + s;

    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            vector<int> cycle;
            int current = i;
            while (!visited[current])
            {
                visited[current] = true;
                cycle.push_back(current);
                current = p[current];
            }

            int black_count = 0;
            for (int index : cycle)
            {
                if (s[index] == '0')
                {
                    black_count++;
                }
            }

            for (int index : cycle)
            {
                F[index] = black_count;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << F[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
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