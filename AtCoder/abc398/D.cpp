#include <bits/stdc++.h>
using namespace std;

struct pair_hash
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, R, C;
    cin >> N >> R >> C;
    string S;
    cin >> S;

    vector<int> dr_total(N + 1, 0);
    vector<int> dc_total(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        char c = S[i - 1];
        int dr = 0, dc = 0;
        if (c == 'N')
            dr = -1;
        else if (c == 'S')
            dr = 1;
        else if (c == 'W')
            dc = -1;
        else if (c == 'E')
            dc = 1;
        dr_total[i] = dr_total[i - 1] + dr;
        dc_total[i] = dc_total[i - 1] + dc;
    }

    unordered_map<pair<int, int>, int, pair_hash> first_occurrence;
    for (int k = 0; k <= N; ++k)
    {
        pair<int, int> key = {dr_total[k], dc_total[k]};
        if (first_occurrence.find(key) == first_occurrence.end())
        {
            first_occurrence[key] = k;
        }
    }

    string result;
    for (int t = 1; t <= N; ++t)
    {
        int target_dr = dr_total[t] - R;
        int target_dc = dc_total[t] - C;
        pair<int, int> target = {target_dr, target_dc};

        if (first_occurrence.count(target))
        {
            int k = first_occurrence[target];
            result += (k <= t) ? '1' : '0';
        }
        else
        {
            result += '0';
        }
    }

    cout << result << '\n';
    return 0;
}