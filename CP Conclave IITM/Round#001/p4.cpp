#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int flag = 0;
        while (n != 0)
        {
            int rem = n % 3;
            if (rem > 1)
                flag = 1;
            n = n / 3;
        }
        if(flag == 1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}