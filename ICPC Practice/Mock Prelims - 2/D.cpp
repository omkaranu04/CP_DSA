#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> A(n), B(n);
        for (auto &x : A)
            cin >> x;
        for (auto &x : B)
            cin >> x;
        ll sumA = 0, sumB = 0;
        for (auto &x : A)
            sumA += x;
        for (auto &x : B)
            sumB += x;
        if (sumA != sumB)
        {
            cout << -1 << endl;
            continue;
        }
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        ll psA = 0, psB = 0;
        bool flag = true;
        for (ll i = 0; i < n; i++)
        {
            psA += A[i];
            psB += B[i];
            if (psA < psB)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
            continue;
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++)
            ans += llabs(B[i] - A[i]);
        cout << ans / 2 << endl;
    }
    return 0;
}