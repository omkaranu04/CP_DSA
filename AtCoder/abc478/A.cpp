#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M;
    cin >> N >> M;
    vector<ll> x(N, 0);
    while (M > 0)
    {
        for (ll i = 0; i < N; i++)
        {
            x[i]++;
            M--;
            if (M == 0)
                break;
        }
    }
    for (auto &p : x)
        cout << p << endl;
    return 0;
}