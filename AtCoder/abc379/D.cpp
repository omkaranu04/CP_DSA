#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q;
    cin >> q;
    vector<ll> trees(q + 1);
    trees[0] = 0;
    queue<ll> que;
    for (int i = 0; i < q; i++)
    {
        int qt;
        cin >> qt;
        if (qt == 1)
        {
            trees[i + 1] = trees[i];
            que.push(i);
        }
        if (qt == 2)
        {
            ll days;
            cin >> days;
            trees[i + 1] = trees[i] + days;
        }
        if (qt == 3)
        {
            trees[i + 1] = trees[i];
            ll h;
            cin >> h;
            ll ans = 0;
            while (!que.empty())
            {
                if (trees[i + 1] - trees[que.front()] >= h)
                {
                    que.pop();
                    ans++;
                }
                else
                {
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}