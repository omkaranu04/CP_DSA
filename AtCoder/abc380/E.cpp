#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> idx_clr, clr_cnt;
    for (int i = 1; i <= n; i++)
    {
        idx_clr[i] = i;
        clr_cnt[i]++;
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x, c;
            cin >> x >> c;
            int curr_color = idx_clr[x];
            while (x <= n && idx_clr[x] == curr_color)
            {
                idx_clr[x] = c;
                clr_cnt[curr_color]--;
                clr_cnt[c]++;
                x++;
            }
        }
        else
        {
            int c;
            cin >> c;
            cout << clr_cnt[c] << "\n";
        }
    }
    return 0;
}