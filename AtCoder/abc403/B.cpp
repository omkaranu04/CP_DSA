#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, u;
    cin >> t >> u;
    ll tlen = t.length(), ulen = u.length();
    bool possible = false;
    for (int i = 0; i <= tlen - ulen; i++)
    {
        bool match = true;
        for (int j = 0; j < ulen; j++)
        {
            if (t[i + j] != '?' && t[i + j] != u[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            possible = true;
            break;
        }
    }
    cout << (possible ? "Yes" : "No") << endl;
    return 0;
}
