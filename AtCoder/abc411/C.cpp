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
    ll n, q;
    cin>>n>>q;
    vector<ll> arr(n+2, 0);
    ll ans = 0;
    while(q--)
    {
        ll a;
        cin>>a;
        ll l = arr[a-1], curr = arr[a], r = arr[a+1];
        if(curr==0)
        {
            arr[a]=1;
            if(l==0 && r==0) ans++;
            if(l==1 && r==1) ans--;
        }
        else
        {
            arr[a]=0;
            if(l==0 && r==0) ans--;
            if(l==1 && r==1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}