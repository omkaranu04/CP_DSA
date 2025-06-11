#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct Node
{
    ll cnt;
    multiset<string> wend;
    vector<Node *> ch;
    Node() : cnt(0), ch(26, NULL) {}
};
struct StringTrie
{
    Node *root;
    StringTrie() { root = new Node; }
    void insert(string s)
    {
        Node *curr = root;
        for (auto c : s)
        {
            ll ch = c - 'a';
            if (curr->ch[ch] == NULL)
                curr->ch[ch] = new Node;
            curr = curr->ch[ch];
            curr->cnt++;
            curr->wend.insert(s);
        }
    }
    void query(string s, ll k)
    {
        Node *curr = root;
        for (ll i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (curr->ch[c - 'a'] == NULL)
            {
                while (i < s.length())
                {
                    cout << endl;
                    i++;
                }
                continue;
            }

            curr = curr->ch[c - 'a'];
            if (curr->wend.size() > 0)
            {
                auto it = curr->wend.begin();
                for (ll j = 0; j < k; j++)
                {
                    if (it != curr->wend.end())
                    {
                        cout << *it << " ";
                        it++;
                    }
                    else
                        break;
                }
            }
            cout << endl;
        }
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, maxlen, q;
    cin >> n >> maxlen >> q;
    StringTrie trie;
    for (ll i = 0; i < n; i++)
    {
        ll len;
        string s;
        cin >> len >> s;
        trie.insert(s);
    }
    while (q--)
    {
        ll len, k;
        string s;
        cin >> len >> s >> k;
        trie.query(s, k);
    }
    return 0;
}