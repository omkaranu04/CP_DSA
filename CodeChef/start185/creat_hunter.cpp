#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        long long H;
        cin >> N >> H;
        
        long long max_d1 = 0;  // Max damage for S=1 weapons
        long long max_d2 = 0;  // Max damage for S=2 weapons
        
        for (int i = 0; i < N; ++i) {
            int S, D;
            cin >> S >> D;
            if (S == 1) max_d1 = max(max_d1, 1LL * D);
            else max_d2 = max(max_d2, 1LL * D);
        }
        
        long long ans = LLONG_MAX;
        if (max_d1 > 0) {
            long long hits = (H + max_d1 - 1) / max_d1;
            ans = min(ans, hits);
        }
        
        if (max_d2 > 0) {
            long long hits = (H + max_d2 - 1) / max_d2;
            ans = min(ans, hits * 2);
        }
        
        if (max_d1 > 0 && max_d2 > 0) {
            long long x = H / max_d2;  
            long long rem = H - x * max_d2; 
            
            if (rem == 0) {
                ans = min(ans, x * 2);
            } else if (rem <= max_d1) {
                ans = min(ans, x * 2 + 1);
            } else {
                long long s1_hits = (rem + max_d1 - 1) / max_d1;
                ans = min(ans, x * 2 + s1_hits);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}