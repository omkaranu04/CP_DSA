#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
using namespace std;

void solve()
{
    int n;
    string a, b;
    cin >> n >> a >> b;
    int freq[10] = {0};
    string ans;
    for (char c : a)
        freq[c - '0']++;
    if (b[0] == '0')
    {
        bool allZero = freq[0] == n;
        if (allZero)
        {
            cout << -1;
            return;
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (freq[i])
                {
                    ans.pb(i + '0');
                    freq[i]--;
                    break;
                }
            }
            for (int i = 0; i <= 9; i++)
            {
                while (freq[i]--)
                {
                    ans.pb(i + '0');
                }
            }
            cout << ans << endl;
            return;
        }
    }
    int tempFreq[10];
    memcpy(tempFreq, freq, sizeof(freq));
    int l = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = b[i] - '0' + 1; j <= 9; j++)
        {
            if (tempFreq[j])
            {
                l = i;
                break;
            }
        }
        if (tempFreq[b[i] - '0'])
        {
            tempFreq[b[i] - '0']--;
        }
        else
            break;
    }
    if (l == -1)
    {
        cout << -1;
        return;
    }
    memset(freq, 0, sizeof(freq));
    for (char c : a)
        freq[c - '0']++;
    for (int i = 0; i < l; i++)
    {
        ans.pb(b[i]);
        freq[b[i] - '0']--;
    }
    for (int j = b[l] - '0' + 1; j <= 9; j++)
    {
        if (freq[j])
        {
            ans.pb(j + '0');
            freq[j]--;
            break;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        while (freq[i]--)
        {
            ans.pb(i + '0');
        }
    }
    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}