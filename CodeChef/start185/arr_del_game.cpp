#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long solve()
{
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }

    // Min-heap to store the elements Alice will take
    priority_queue<int, vector<int>, greater<int>> pq;

    // Process the array in pairs
    for (int i = 0; i < n; i++)
    {
        // Add both elements of the current pair
        pq.push(a[2 * i]);
        pq.push(a[2 * i + 1]);

        // If we have more than i+1 elements, remove the smallest
        if (pq.size() > i + 1)
        {
            pq.pop();
        }
    }

    // Calculate Alice's score
    long long score = 0;
    while (!pq.empty())
    {
        score += pq.top();
        pq.pop();
    }

    return score;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }

    return 0;
}