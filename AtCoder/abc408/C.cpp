#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> diff(N + 2, 0);

    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;
        diff[L] += 1;
        diff[R + 1] -= 1;
    }

    int minCover = INT_MAX;
    int currCover = 0;
    for (int i = 1; i <= N; ++i) {
        currCover += diff[i];
        minCover = min(minCover, currCover);
    }

    cout << minCover << "\n";
    return 0;
}
