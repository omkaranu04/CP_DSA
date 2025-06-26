#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct Node
{
    string s;
    Node *prev;
    Node(string &_s, Node *p) : s(_s), prev(p) {}
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<Node *> pcs(n, NULL);
    Node *server = NULL;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p;
            cin >> p;
            pcs[p - 1] = server;
        }
        else if (t == 2)
        {
            ll p;
            string s;
            cin >> p >> s;
            pcs[p - 1] = new Node(s, pcs[p - 1]);
        }
        else
        {
            ll p;
            cin >> p;
            server = pcs[p - 1];
        }
    }
    vector<string> x;
    for (Node *curr = server; curr; curr = curr->prev)
        x.push_back(curr->s);
    reverse(x.begin(), x.end());
    for (auto it = x.begin(); it != x.end(); it++)
        cout << *it;
    return 0;
}