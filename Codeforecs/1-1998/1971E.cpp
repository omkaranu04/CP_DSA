#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, q;
        cin >> n >> k >> q;
        vector<long long int> a(k + 1), b(k + 1);
        a[0] = 0;
        b[0] = 0;
        for (long long int i = 1; i <= k; i++)
        {
            cin >> a[i];
        }
        for (long long int i = 1; i <= k; i++)
        {
            cin >> b[i];
        }
        vector<long long int> answer;
        while (q--)
        {
            long long int d;
            cin >> d;
            long long int l = 0, r = k;
            while (l <= r)
            {
                long long int mid = l + r >> 1;
                if (a[mid] > d)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            if (a[r] == d)
            {
                answer.push_back(b[r]);
                continue;
            }
            long long int ace = b[r] + (d - a[r]) * (b[r + 1] - b[r]) / (a[r + 1] - a[r]);
            answer.push_back(ace);
        }
        for (auto i : answer)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}