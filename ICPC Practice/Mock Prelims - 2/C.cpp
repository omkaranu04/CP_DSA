// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define endl "\n"
// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ll T;
//     cin >> T;
//     while (T--)
//     {
//         ll a, b, c;
//         cin >> a >> b >> c;
//         ll c1 = c % 3, b1 = b % 2, a1 = a;
//         if (b1)
//         {
//             cout << -1 << endl;
//             continue;
//         }
//         else if (c1 && (a1 + (b / 2)) < c1)
//         {
//             cout << -1 << endl;
//             continue;
//         }
//         else
//         {
//             for (ll i = 1; i <= min(a, c1); i++)
//             {
//                 cout << 4 * (i - 1) + 1 << " " << 4 * i << endl;
//                 cout << 4 * (i - 1) + 2 << " " << 4 * (i - 1) + 3 << endl;
//             }
//             ll j = 4 * (min(a, c1)) + 1;
//             c = c - min(a, c1);
//             a = a - min(a, c1);
//             if (c1 > a1)
//             {
//                 ll x = c1 - a1;
//                 while (x--)
//                 {
//                     cout << j << " " << j + 2 << endl;
//                     cout << j + 1 << " " << j + 4 << endl;
//                     cout << j + 3 << " " << j + 5 << endl;
//                     j += 6;
//                     b -= 2;
//                     c -= 1;
//                 }
//             }

//             while (a--)
//             {
//                 cout << j << " " << j + 1 << endl;
//                 j += 2;
//             }
//             while (b--)
//             {
//                 cout << j << " " << j + 2 << endl;
//                 cout << j + 1 << " " << j + 3 << endl;
//                 j += 4;
//                 b -= 1;
//             }
//             while (c--)
//             {
//                 cout << j << " " << j + 3 << endl;
//                 cout << j + 1 << " " << j + 4 << endl;
//                 cout << j + 2 << " " << j + 5 << endl;
//                 j += 6;
//                 c -= 2;
//             }
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void emit(ll a, ll b)
{
    cout << a << " " << b << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll r = c % 3;
        if ((b % 2 == 1) || (r == 1 && a == 0 && b == 0) || (r == 2 && b == 0 && a < 2))
        {
            cout << -1 << endl;
            continue;
        }
        ll t = 1;
        if (r == 1)
        {
            if (a >= 1)
            {
                emit(t, t + 3);
                emit(t + 1, t + 2);
                a--;
                t += 4;
            }
            else
            {
                emit(t, t + 2);
                emit(t + 1, t + 4);
                emit(t + 3, t + 5);
                b -= 2;
                t += 6;
            }
        }
        else if (r == 2)
        {
            if (b >= 2)
            {
                emit(t, t + 2);
                emit(t + 1, t + 4);
                emit(t + 3, t + 6);
                emit(t + 5, t + 7);
                b -= 2;
                t += 8;
            }
            else
            {
                emit(t, t + 3);
                emit(t + 1, t + 2);
                t += 4;
                emit(t, t + 3);
                emit(t + 1, t + 2);
                t += 4;
                a -= 2;
            }
            c -= 2;
        }
        for (ll i = 0; i <= c / 3 - 1; i++)
        {
            emit(t, t + 3);
            emit(t + 1, t + 4);
            emit(t + 2, t + 5);
            t += 6;
        }
        for (ll i = 0; i <= b / 2 - 1; i++)
        {
            emit(t, t + 2);
            emit(t + 1, t + 3);
            t += 4;
        }
        for (ll i = 0; i <= a - 1; i++)
        {
            emit(t, t + 1);
            t += 2;
        }
    }
    return 0;
}