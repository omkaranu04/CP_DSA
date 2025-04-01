#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    unordered_set<int> leftSet, rightSet;
    vector<int> leftCount(N), rightCount(N);

    for (int i = 0; i < N; i++)
    {
        leftSet.insert(A[i]);
        leftCount[i] = leftSet.size();
    }

    for (int i = N - 1; i >= 0; i--)
    {
        rightSet.insert(A[i]);
        rightCount[i] = rightSet.size();
    }

    int maxSum = 0;
    for (int i = 0; i < N - 1; i++)
        maxSum = max(maxSum, leftCount[i] + rightCount[i + 1]);

    cout << maxSum;
    return 0;
}