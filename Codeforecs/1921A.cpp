#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    vector<pair<int, int>> pt(4);
    int a = INT_MAX, c = INT_MAX;
    int b = INT_MIN, d = INT_MIN;
    for (int i = 0; i < 4; i++)
    {
        cin >> pt[i].first >> pt[i].second;
        if (pt[i].first < a)
            a = pt[i].first;
        if (pt[i].first > b)
            b = pt[i].first;
        if (pt[i].second < c)
            c = pt[i].second;
        if (pt[i].second > d)
            d = pt[i].second;
    }
    cout << (b - a) * (d - c) << endl;
    return;
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