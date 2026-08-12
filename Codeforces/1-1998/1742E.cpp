#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<long long> a(n + 1);
        vector<long long> ps(n + 1);
        vector<long long> maxi(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            cin >> a[i];
            ps[i] = ps[i - 1] + a[i];
            maxi[i] = max(maxi[i - 1], a[i]);
        }
        for (int i = 0; i < q; i++)
        {
            long long int ans = 0;
            long long x;
            cin >> x;
            int k = upper_bound(maxi.begin(), maxi.end(), x) - maxi.begin() - 1;
            if (k >= 0)
            {
                ans = ps[k];
            }
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}