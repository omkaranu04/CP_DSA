#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string> ans;
int rec(int rem, vector<int> &dp)
{
    if (rem == 0)
        return 0;

    if (dp[rem] != -1)
        return dp[rem];

    for (int i = 0; (1 << i) <= rem; i++)
    {
        if (rec(rem - (1 << i), dp) == 0)
            return dp[rem] = 1;
    }
    return dp[rem] = 0;
}
void solve()
{
    int x;
    cin >> x;
    // vector<int> dp(x + 1, -1);
    // rec(x, dp) ? ans.push_back("Vivek") : ans.push_back("Abhishek");
    if (x % 3 == 0)
        cout << "Abhishek\n";
    else
        cout << "Vivek\n";
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
    // for (auto x : ans)
    //     cout << x << "\n";
    return 0;
}