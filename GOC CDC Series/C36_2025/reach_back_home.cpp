#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    string T;
    cin >> T;
    ll cx = 0, cy = 0, maxeast = 0, maxwest = 0;
    for (auto c : T)
    {
        if (c == 'N')
            cy++;
        if (c == 'S')
            cy--;
        if (c == 'E')
        {
            cx++;
            if (cx > 0)
                maxeast = max(maxeast, cx);
        }
        if (c == 'W')
        {
            cx--;
            if (cx < 0)
                maxwest = min(maxwest, cx);
        }
    }
    // cout << maxwest << " " << maxeast << endl;
    // cout << cx << " " << cy << endl;

    // round path from east
    string ans1 = "";
    for(ll i=cx;i<=maxeast;i++) ans1 += 'E';
    if(cy>0) for(ll i=0;i<cy;i++) ans1 += 'S';
    else for(ll i=0;i<-cy;i++) ans1 += 'N';
    for(ll i=0;i<maxeast+1;i++) ans1 += 'W';

    // cout<<ans1.length()<<" "<<ans1<<endl;

    // round path from west
    string ans2 = "";
    for(ll i=cx;i>=maxwest;i--) ans2 += 'W';
    if(cy>0) for(ll i=0;i<cy;i++) ans2 += 'S';
    else for(ll i=0;i<-cy;i++) ans2 += 'N';
    for(ll i=0;i<abs(maxwest)+1;i++) ans2+='E';

    // cout<<ans2.length()<<" "<<ans2<<endl;

    if(ans1.length()<ans2.length()) cout<<ans1<<endl;
    else cout<<ans2<<endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}