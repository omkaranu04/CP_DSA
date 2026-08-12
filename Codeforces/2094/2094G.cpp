#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll q;
    cin >> q;
    ll score = 0, sum = 0, rscore = 0;
    deque<ll> dq;
    bool reversed = false;
    while (q--)
    {
        ll s;
        cin >> s;
        if (s == 1)
        {
            ll n = dq.size();
            if (!reversed)
            {
                ll x = dq.back();
                dq.pop_back();
                dq.push_front(x);

                score -= x * n;
                score += sum;
                rscore -= sum;
                rscore += x * n;
            }
            else
            {
                ll x = dq.front();
                dq.pop_front();
                dq.push_back(x);

                rscore -= n * x;
                rscore += sum;
                score -= sum;
                score += x * n;
            }
        }
        else if (s == 2)
        {
            reversed = !reversed;
        }
        else if (s == 3)
        {
            ll k;
            cin >> k;
            if (!reversed)
            {
                dq.push_back(k);
                sum += k;

                score += (k * dq.size());
                rscore += sum;
            }
            else
            {
                dq.push_front(k);
                sum += k;

                score += sum;
                rscore += (k * dq.size());
            }
        }

        // cout << "Ans : ";
        if (!reversed)
            cout << score << endl;
        else
            cout << rscore << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}