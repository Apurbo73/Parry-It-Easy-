#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; long long X;
        cin >> N >> X;
        vector<long long> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        
        vector<long long> need(N+1, 0);
        need[N] = 0; 

        for (int i = N-1; i >= 0; i--) {
           
            long long dodge_need = max(A[i], need[i+1]);
            long long parry_need = max(B[i], need[i+1] + 1);

            need[i] = min(dodge_need, parry_need);
        }

        if (X < need[0]) {
            cout << 0 << "\n";
            continue;
        }

        int parryCount = 0;
        long long currSkill = X;

        for (int i = 0; i < N; i++) {
         
            if (currSkill >= B[i] && (currSkill - 1) >= need[i+1]) {
                parryCount++;
                currSkill--;
            } else {
                if (currSkill < A[i]) {
                    parryCount = 0;
                    break;
                }
            }
        }

        cout << parryCount << "\n";
    }

    return 0;
}