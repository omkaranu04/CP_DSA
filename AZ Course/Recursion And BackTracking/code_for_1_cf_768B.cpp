#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll getLength(ll x)
{
    if (x <= 1)
        return 1;
    return 2 * getLength(x / 2) + 1;
}

ll countOnes(ll x, ll l, ll r, ll left = 1, ll right = -1)
{
    if (x <= 1)
    {
        if (l <= left && right <= r)
            return x;
        else
            return 0;
    }

    if (right == -1)
        right = getLength(x);

    ll mid = left + (getLength(x / 2));
    ll count = 0;

    if (l <= mid - 1)
        count += countOnes(x / 2, l, r, left, mid - 1);

    if (l <= mid && mid <= r)
        count += (x % 2);

    if (r >= mid + 1)
        count += countOnes(x / 2, l, r, mid + 1, right);

    return count;
}

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;

    cout << countOnes(n, l, r) << endl;
    return 0;
}
