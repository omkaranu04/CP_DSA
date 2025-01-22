#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct prod
{
    ll base_price, curr_price, quan;
};
struct compare
{
    bool operator()(prod a, prod b)
    {
        return a.curr_price > b.curr_price;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    priority_queue<prod, vector<prod>, compare> pq;
    for (ll i = 1; i <= n; i++)
    {
        ll a;
        cin >> a;
        pq.push({a, a, 1});
    }
    ll ans = 0, cost = 0;
    while (1)
    {
        ans += 1;
        cost += pq.top().curr_price;
        // cout << ans << " " << cost << endl;
        if (cost <= m)
        {
            prod temp = pq.top();
            pq.pop();
            temp.quan += 2;
            temp.curr_price = (temp.quan * temp.base_price);
            pq.push(temp);
        }
        else
        {
            ans -= 1;
            cost -= pq.top().curr_price;
            break;
        }
    }
    // cout << ans << " " << cost << endl;
    cout << ans << endl;
    return 0;
}