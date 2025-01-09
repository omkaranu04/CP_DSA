#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n < 3)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> dp1(n, 0), dp2(n, 0), inca, deca;
    for (int i = 0; i < n; i++)
    {
        if (inca.empty() || inca.back() < arr[i])
            inca.push_back(arr[i]);
        else
        {
            auto it = lower_bound(inca.begin(), inca.end(), arr[i]) - inca.begin();
            inca[it] = arr[i];
        }
        dp1[i] = inca.size();
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (deca.empty() || deca.back() < arr[i])
            deca.push_back(arr[i]);
        else
        {
            auto it = lower_bound(deca.begin(), deca.end(), arr[i]) - deca.begin();
            deca[it] = arr[i];
        }
        dp2[i] = deca.size();
    }
    int ans = INT_MAX;
    bool valid = false;
    for (int i = 0; i < n; i++)
    {
        if (dp1[i] > 1 && dp2[i] > 1)
        {
            valid = true;
            ans = min(ans, n - (dp1[i] + dp2[i] - 1));
        }
    }
    // cout << "ans : ";
    cout << (valid ? ans : -1) << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}