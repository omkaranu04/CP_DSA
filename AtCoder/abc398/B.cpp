#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isFullHouse(vector<int> &A)
{
    unordered_map<int, int> freq;

    for (int num : A)
    {
        freq[num]++;
    }

    for (auto it1 = freq.begin(); it1 != freq.end(); ++it1)
    {
        for (auto it2 = freq.begin(); it2 != freq.end(); ++it2)
        {
            if (it1 == it2)
                continue;

            if (it1->second >= 3 && it2->second >= 2)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> A(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> A[i];
    }

    if (isFullHouse(A))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
