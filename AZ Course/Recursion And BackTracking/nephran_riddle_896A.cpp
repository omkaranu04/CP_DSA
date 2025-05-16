#include <bits/stdc++.h>
using namespace std;

#define ll long long

const string base = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string pre = "What are you doing while sending \"";
const string mid = "\"? Are you busy? Will you send \"";
const string suf = "\"?";

const ll INF = 1e18 + 10;
vector<ll> len(1e5 + 5);

void precompute_lengths()
{
    len[0] = base.length();
    for (int i = 1; i <= 1e5; ++i)
    {
        len[i] = pre.length() + len[i - 1] + mid.length() + len[i - 1] + suf.length();
        if (len[i] > INF)
            len[i] = INF;
    }
}

char get_char(int n, ll k)
{
    if (k <= 0)
        return '.';
    if (n == 0)
    {
        if (k > len[0])
            return '.';
        return base[k - 1];
    }

    if (k <= pre.length())
        return pre[k - 1];
    k -= pre.length();

    if (k <= len[n - 1])
        return get_char(n - 1, k);
    k -= len[n - 1];

    if (k <= mid.length())
        return mid[k - 1];
    k -= mid.length();

    if (k <= len[n - 1])
        return get_char(n - 1, k);
    k -= len[n - 1];

    if (k <= suf.length())
        return suf[k - 1];

    return '.';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute_lengths();

    int q;
    cin >> q;
    string result;

    while (q--)
    {
        int n;
        ll k;
        cin >> n >> k;
        result += get_char(n, k);
    }

    cout << result << '\n';
    return 0;
}
