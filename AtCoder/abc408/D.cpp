#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        string S;
        cin >> N >> S;

        int totalOnes = 0;
        for (char c : S)
        {
            if (c == '1')
                ++totalOnes;
        }

        int maxEndingHere = 0;
        int maxSoFar = 0;
        for (char c : S)
        {
            int v = (c == '1') ? 1 : -1;
            maxEndingHere = max(v, maxEndingHere + v);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        int answer = totalOnes - maxSoFar;
        cout << answer << "\n";
    }

    return 0;
}
