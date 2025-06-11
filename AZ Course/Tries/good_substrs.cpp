#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct Node
{
    ll cnt;
    vector<Node *> ch;
    Node() : cnt(0LL), ch(26, NULL) {}
};
struct StringTrie
{
    Node *root;
    string gs;
    StringTrie(const string &_gs) : gs(_gs) { root = new Node; }
    void insert(string s)
    {
        Node *curr = root;
        for (auto c : s)
        {
            if (curr->ch[c - 'a'] == NULL)
                curr->ch[c - 'a'] = new Node;
            curr = curr->ch[c - 'a'];
            curr->cnt++;
        }
    }
    void query(ll k, ll &ans, Node *root)
    {
        for (ll i = 0; i < 26; i++)
        {
            if (root->ch[i] != NULL)
            {
                if (k - (gs[i] == '0') >= 0)
                {
                    ans++;
                    query(k - (gs[i] == '0'), ans, root->ch[i]);
                }
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, gs;
    cin >> s;
    cin >> gs;
    ll k;
    cin >> k;
    StringTrie trie(gs);
    ll n = s.length();
    for (ll i = 0; i < n; i++)
        trie.insert(s.substr(i, n - i));
    ll ans = 0;
    trie.query(k, ans, trie.root);
    cout << ans << endl;
    return 0;
}