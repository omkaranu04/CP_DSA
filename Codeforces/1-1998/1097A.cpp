#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string table;
    cin >> table;
    vector<string> hand(5);
    bool flag = false;
    for (int i = 0; i < 5; i++)
    {
        cin >> hand[i];
        if (hand[i][0] == table[0] || hand[i][1] == table[1])
            flag = true;
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
