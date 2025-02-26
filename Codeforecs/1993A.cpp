#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> count(4, 0);
        int question_marks = 0;

        for (char c : s)
        {
            if (c == '?')
            {
                question_marks++;
            }
            else
            {
                count[c - 'A']++;
            }
        }
        ll correct = 0;
        for (int i = 0; i < 4; i++)
        {
            correct += min(count[i], n);
        }
        cout << correct << endl;
    }
    return 0;
}