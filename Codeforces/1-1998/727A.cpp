#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
vector<ll> ans;
ll a, b;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    ll num = b;
    while (num > a)
    {
        if (num % 10 == 1)
            num = (num - 1) / 10;
        else if (num % 2 == 0)
            num = num / 2;
        else
            break;
        ans.push_back(num);
    }
    if (num == a)
    {
        reverse(ans.begin(), ans.end());
        ans.push_back(b);
        cout << "YES\n"
             << ans.size() << endl;
        for (auto x : ans)
            cout << x << " ";
    }
    else
        cout << "NO\n";
    return 0;
}