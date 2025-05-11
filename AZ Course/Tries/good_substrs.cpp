#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

class trieNode
{
public:
    ll cnt;
    multiset<string> wend;
    trieNode *child[26];
    trieNode()
    {
        cnt = 0;
        wend.clear();
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void insert(string s, ll start, trieNode *root)
{
    trieNode *curr = root;
    for (int i = start; i < s.length(); i++)
    {
        ll x = s[i] - 'a';
        if (curr->child[x] == NULL)
            curr->child[x] = new trieNode();
        curr = curr->child[x];
    }
}

void Ssearch(ll k, ll &ans, trieNode *root, string &a)
{
    for (ll i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            if (k - (a[i] == '0') >= 0)
            {
                ans++;
                Ssearch(k - (a[i] == '0'), ans, root->child[i], a);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, a;
    cin >> s >> a;
    ll k;
    cin >> k;

    trieNode *root = new trieNode();

    for (int i = 0; i < s.length(); i++)
        insert(s, i, root);

    ll ans = 0;
    Ssearch(k, ans, root, a);
    cout << ans << endl;
    return 0;
}