#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<vector<int>> b(n, vector<int>(n, 0));
    vector<int> row_count(n, 0), col_count(n, 0);
    int diag_count = 0, rdiag_count = 0;

    for (int turn = 1; turn <= t; turn++) {
        int l;
        cin >> l;
        l--;
        int i = l / n;
        int j = l % n;
        b.at(i).at(j) = 1;
        if (++row_count[i] == n || ++col_count[j] == n || (i == j && ++diag_count == n) || (i == n - 1 - j && ++rdiag_count == n)){
            cout << turn << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
