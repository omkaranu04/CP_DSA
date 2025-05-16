#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
string r, c, s;
map<char, ll> mp;
vector<string> start[3];
void generate(ll level)
{
    if (level == n)
    {
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] != '.')
            {
                start[s[i] - 'A'].push_back(s);
                return;
            }
        }
        return;
    }
    for (auto &x : mp)
    {
        if (x.second == 0)
            continue;
        s.push_back(x.first);
        x.second--;
        generate(level + 1);
        x.second++;
        s.pop_back();
    }
}
vector<string> sol, final_sol;
bool done = false;
void rec(ll level, string currdone)
{
    if (level == n)
    {
        bool final = true;
        for (ll j = 0; j < n; j++)
        {
            set<char> tmp;
            for (ll i = 0; i < n; i++)
            {
                if (sol[i][j] != '.')
                    tmp.insert(sol[i][j]);
            }
            if (tmp.size() != 3)
            {
                final = false;
                break;
            }
        }
        if (final)
        {
            done = true;
            final_sol = sol;
        }
        return;
    }

    ll firstcharrow = r[level] - 'A';
    for (auto &ch : start[firstcharrow])
    {
        if (done)
            break;
        bool valid = true;
        for (ll pos = 0; pos < n; pos++)
        {
            if (ch[pos] != '.' && currdone[pos] == '0' && ch[pos] != c[pos])
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            sol.push_back(ch);
            string newdone = currdone;
            for (ll pos = 0; pos < n; pos++)
            {
                if (ch[pos] != '.')
                    newdone[pos] = '1';
            }
            rec(level + 1, newdone);
            sol.pop_back();
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> r >> c;
    mp['A'] = 1;
    mp['B'] = 1;
    mp['C'] = 1;
    mp['.'] = n - 3;
    generate(0);
    string donee(n, '0');
    rec(0, donee);
    if (done)
    {
        cout << "Yes\n";
        for (auto &x : final_sol)
            cout << x << endl;
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}