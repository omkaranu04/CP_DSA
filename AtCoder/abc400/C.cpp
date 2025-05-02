#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define endl "\n"
vector<ll> p2;
void fill()
{
    p2.push_back(2);
    for (int i = 1; i <= 62; i++)
    {
        p2.push_back(p2[i - 1] * 2);
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill();
    ll n;
    cin >> n;
    ll ans = 0;
    for (int d = 1;; d++)
    {
        ll pow2 = (1ULL << d);
        if (pow2 > n)
            break;

        long double ratio = (long double)n / (long double)pow2;
        ll M = (ll)floor(sqrt(ratio));
        if (M < 1)
            break; 
        ans += (M + 1) / 2;
    }
    cout << ans << endl;
    return 0;
}