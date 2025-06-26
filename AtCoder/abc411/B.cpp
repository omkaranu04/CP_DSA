#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vector<ll> d(n-1);
    for(ll i=0;i<n-1;i++) cin>>d[i];
    vector<ll> ps(n);
    ps[0] = 0;
    for(ll i=1;i<n;i++) ps[i] = ps[i-1] + d[i-1];
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=i+1;j<n;j++)
        {
            cout<<ps[j]-ps[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}