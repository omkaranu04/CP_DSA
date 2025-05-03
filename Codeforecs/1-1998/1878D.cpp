#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l[k], r[k];
        for (int i = 0; i < k; i++)
        {
            cin >> l[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> r[i];
        }
        int q;
        cin >> q;
        int x[q];
        int modif[n + 1] = {0};
        for (int i = 0; i < q; i++)
        {
            cin >> x[i];
            int idx = lower_bound(r, r + k, x[i]) - r;
            int a = min(x[i], l[idx] + r[idx] - x[i]);
            int b = max(x[i], l[idx] + r[idx] - x[i]);
            modif[a - 1] += 1;
            modif[b] -= 1;
        }
        for (int i = 1; i < n; i++)
        {
            modif[i] += modif[i - 1];
        }
        for (int idx = 0; idx < k; idx++)
        {
            int lo = l[idx] - 1, hi = r[idx] - 1;

            while (lo < hi)
            {
                if (modif[lo] % 2 != 0)
                {
                    swap(s[lo], s[hi]);
                }
                lo++;
                hi--;
            }
        }
        cout << s << endl;
    }
    return 0;
}