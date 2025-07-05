#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

vector<pair<char, ll>> runLength(const string &str)
{
    vector<pair<char, ll>> seg;
    ll cnt = 1;
    for (size_t i = 1; i < str.size(); ++i)
    {
        if (str[i] == str[i - 1])
            ++cnt;
        else
        {
            seg.emplace_back(str[i - 1], cnt);
            cnt = 1;
        }
    }
    seg.emplace_back(str.back(), cnt);
    return seg;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    if (!(cin >> S >> T))
        return 0;

    auto segS = runLength(S);
    auto segT = runLength(T);

    if (segS.size() != segT.size())
    {
        cout << "No\n";
        return 0;
    }

    for (size_t i = 0; i < segS.size(); ++i)
    {
        char cS = segS[i].first, cT = segT[i].first;
        ll lenS = segS[i].second, lenT = segT[i].second;

        if (cS != cT)
        {
            cout << "No\n";
            return 0;
        }
        if (lenS > lenT)
        {
            cout << "No\n";
            return 0;
        }
        if (lenS == 1 && lenT != 1)
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}