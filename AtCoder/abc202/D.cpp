#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
__int128 choose(int n, int k)
{
    if (k > n)
        return 0;
    if (k > n - k)
        k = n - k;
    __int128 c = 1;
    for (int i = 1; i <= k; i++)
    {
        c = c * (n - k + i) / i;
    }
    return c;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll A, B, K;
    cin >> A >> B >> K;
    string ans = "";
    while (A > 0 && B > 0)
    {
        ll tmp = (ll)choose(A + B - 1, A - 1);
        if (K <= tmp)
        {
            ans += "a";
            A--;
        }
        else
        {
            ans += "b";
            K -= tmp;
            B--;
        }
    }
    if (A > 0)
        ans += string(A, 'a');
    if (B > 0)
        ans += string(B, 'b');
    cout << ans << endl;
    return 0;
}