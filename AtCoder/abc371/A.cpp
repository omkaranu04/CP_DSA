#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char sab, sac, sbc;
    cin >> sab >> sac >> sbc;
    if ((sab == '<' && sbc == '<') || (sab == '>' && sbc == '>'))
        cout << "B\n";
    else if ((sab == '>' && sac == '<') || (sab == '<' && sac == '>'))
        cout << "A\n";
    else
        cout << "C\n";
    return 0;
}