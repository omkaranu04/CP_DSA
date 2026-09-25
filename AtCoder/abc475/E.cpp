#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct Node
{
    ll child[2];
    ll cnt;
    Node()
    {
        child[0] = child[1] = -1;
        cnt = 0;
    }
};
struct Trie
{
    ll N, K, sz;
    vector<Node> t;
    Trie(ll _N, ll _K)
    {
        N = _N;
        K = _K;
        sz = 1;
        t.emplace_back();
    }
    void insert(string s, ll d)
    {
        ll node = 0;
        t[node].cnt += d;
        for (ll i = 0; i < K; i++)
        {
            ll b = (s[i] == 'o');
            if (t[node].child[b] == -1)
            {
                t[node].child[b] = sz++;
                t.emplace_back();
            }
            node = t[node].child[b];
            t[node].cnt += d;
        }
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<string> S(N);
    string T;
    cin >> T;
    for (auto &x : S)
        cin >> x;
    vector<ll> correct(K);
    for (ll i = 0; i < K; i++)
        correct[i] = (T[i] == 'o');

    Trie trie(N, K);
    for (ll i = 0; i < N; i++)
        trie.insert(S[i], 1);
    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll i, j;
        cin >> i >> j;
        i--;
        j--;

        trie.insert(S[i], -1);
        S[i][j] = (S[i][j] == 'o' ? 'x' : 'o');
        trie.insert(S[i], 1);

        ll node = 0, qua = 0;
        bool passes = false;
        for (ll k = 0; k < K; k++)
        {
            ll pAnswer = (S[i][k] == 'o');
            ll cAnswer = correct[k];

            ll cChild = trie.t[node].child[cAnswer];
            ll iChild = trie.t[node].child[cAnswer ^ 1];

            ll cCount = 0;
            if (cChild != -1)
                cCount = trie.t[cChild].cnt;

            if (qua + cCount <= M)
            {
                if (pAnswer == cAnswer)
                {
                    passes = true;
                    break;
                }
                node = iChild;
                qua += cCount;
            }
            else
            {
                if (pAnswer != cAnswer)
                {
                    passes = false;
                    break;
                }
                node = cChild;
            }
        }
        cout << (passes ? "Yes\n" : "No\n");
    }
    return 0;
}