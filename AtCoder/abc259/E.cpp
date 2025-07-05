#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using u64 = unsigned long long;

static u64 splitmix64(u64 x)
{
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

struct Info
{
    int64 max1 = 0;
    int cnt1 = 0;
    int64 max2 = 0;
    int id = -1;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<pair<int64, int64>>> num(N);

    unordered_map<int64, Info> mp;
    mp.reserve(400000);

    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        num[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            int64 p, e;
            cin >> p >> e;
            num[i][j] = {p, e};

            auto &inf = mp[p];
            if (e > inf.max1)
            {
                inf.max2 = inf.max1;
                inf.max1 = e;
                inf.cnt1 = 1;
            }
            else if (e == inf.max1)
            {
                ++inf.cnt1;
            }
            else if (e > inf.max2)
            {
                inf.max2 = e;
            }
        }
    }

    for (auto &kv : mp)
    {
        auto &inf = kv.second;
        if (inf.cnt1 < N)
            inf.max2 = max<int64>(inf.max2, 0);
    }

    int M = 0;
    for (auto &kv : mp)
        kv.second.id = M++;
    vector<u64> rnd(M);
    for (int i = 0; i < M; i++)
        rnd[i] = splitmix64(i + 1234567);

    unordered_set<u64> sigs;
    sigs.reserve(N * 2);

    for (int i = 0; i < N; i++)
    {
        u64 sig = 0;
        for (auto [p, e] : num[i])
        {
            const Info &inf = mp[p];
            if (e == inf.max1 && inf.cnt1 == 1)
            {
                sig ^= rnd[inf.id];
            }
        }
        sigs.insert(sig);
    }

    cout << sigs.size() << '\n';
    return 0;
}
