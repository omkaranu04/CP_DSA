#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<vector<char>> rotate(const vector<vector<char>> &a)
{
    int N = a.size();
    vector<vector<char>> b(N, vector<char>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            b[j][N-i-1] = a[i][j];
        }
    }
    return b;
}
int countDifferences(const vector<vector<char>>& a, const vector<vector<char>>& b) {
    int diff = 0;
    int N = a.size();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (a[i][j] != b[i][j])
                ++diff;
    return diff;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N;
    cin>>N;
    vector<vector<char>> S(N, vector<char>(N));
    vector<vector<char>> T(N, vector<char>(N));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>S[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>T[i][j];
        }
    }
    ll ans = 1e9;
    for(int i=0;i<4;i++)
    {
        ll diff = countDifferences(S, T);
        ll ops = diff + i;
        ans = min(ans, ops);
        S = rotate(S);
    }
    cout<<ans<<endl;
    return 0;
}