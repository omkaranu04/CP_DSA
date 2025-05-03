#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        deque<ll> dq(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dq[i];
        }
        while (dq.size() > 1 && k)
        {
            ll m = min(dq.front(), dq.back());
            if (k < 2 * m)
            {
                dq.front() -= k / 2 + k % 2;
                dq.back() -= k / 2;
                k = 0;
            }
            else
            {
                dq.front() -= m;
                dq.back() -= m;
                k -= 2 * m;
            }
            if (dq.front() == 0)
                dq.pop_front();
            if (dq.back() == 0)
                dq.pop_back();
        }
        ll ans = n - dq.size();
        cout << ans + (dq.size() && dq.front() <= k) << endl;
    }
    return 0;
}