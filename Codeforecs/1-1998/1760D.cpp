#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i == 0 || x != ans.back())
            {
                ans.push_back(x);
            }
        }
        int l = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if ((i == 0 || ans[i - 1] > ans[i]) && (i == ans.size() - 1 || ans[i] < ans[i + 1]))
                l++;
        }
        if (l == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}