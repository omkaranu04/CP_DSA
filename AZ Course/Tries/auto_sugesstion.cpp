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

void insert(string s, trieNode *root)
{
    trieNode *curr = root;
    for (auto c : s)
    {
        if (curr->child[c - 'a'] == NULL)
            curr->child[c - 'a'] = new trieNode();
        curr = curr->child[c - 'a'];
        curr->cnt++;
        curr->wend.insert(s);
    }
}

void query(string s, ll k, trieNode *root)
{
    trieNode *curr = root;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (curr->child[c - 'a'] == NULL)
        {
            while (i < s.length())
            {
                cout << endl;
                i++;
            }
            continue;
        }

        curr = curr->child[c - 'a'];
        if (curr->wend.size() > 0)
        {
            auto it = curr->wend.begin();
            for (ll j = 0; j < k; j++)
            {
                if (it != curr->wend.end())
                {
                    cout << (*it) << " ";
                    it++;
                }
                else
                    break;
            }
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    ll n, maxlen, q;
    cin >> n >> maxlen >> q;
    trieNode *root = new trieNode();
    for (ll i = 0; i < n; i++)
    {
        ll len;
        string s;
        cin >> len >> s;
        insert(s, root);
    }
    while (q--)
    {
        ll len, k;
        string s;
        cin >> len >> s >> k;
        query(s, k, root);
    }
    return 0;
}