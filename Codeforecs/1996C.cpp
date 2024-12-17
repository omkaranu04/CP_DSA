#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;

    vector<array<int, ALPHABET_SIZE>> prefix_diff(n + 1, array<int, ALPHABET_SIZE>());

    for (int i = 0; i < n; ++i)
    {
        prefix_diff[i + 1] = prefix_diff[i];
        ++prefix_diff[i + 1][s[i] - 'a'];
        --prefix_diff[i + 1][t[i] - 'a'];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int operations = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            operations += abs(prefix_diff[r][i] - prefix_diff[l - 1][i]);
        }

        cout << operations / 2 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
