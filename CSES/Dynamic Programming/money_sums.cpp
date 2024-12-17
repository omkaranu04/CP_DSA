#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<int> x;
    cin >> n;
    x.resize(n);
    unordered_set<int> dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    // take, not take for first element
    dp[0].insert(0);
    dp[0].insert(x[0]);
    for (int i = 1; i < n; i++)
    {
        for (auto it : dp[i - 1])
        {
            // take not take further
            dp[i].insert(it);
            dp[i].insert(it + x[i]);
        }
    }
    set<int> ans;
    for (auto it : dp[n - 1])
    {
        if (it)
            ans.insert(it);
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}