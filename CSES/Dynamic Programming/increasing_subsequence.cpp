#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        if (lis.empty() || lis.back() < x[i])
            lis.push_back(x[i]);
        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), x[i]);
            *it = x[i];
        }
        // cout << i << " : ";
        // for (auto i : lis)
        //     cout << i << ", ";
        // cout << endl;
    }
    cout << lis.size() << endl;
    return 0;
}