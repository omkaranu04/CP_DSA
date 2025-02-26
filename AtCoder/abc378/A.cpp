#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    unordered_map<int, int> m;
    m[a1]++;
    m[a2]++;
    m[a3]++;
    m[a4]++;
    ll ans = 0;
    for (auto i : m)
    {
        ans += (i.second / 2);
    }
    cout << ans << endl;
    return 0;
}