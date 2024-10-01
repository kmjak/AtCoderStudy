#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vs vector<string>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define rrep(i,s,n) for(int i = s; i >= n; i--)
#define repa(i, x) for(auto i : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    int ans = n * 2 -1;
    int count = 0;

    rep(i, 2, n) {
        if (a[i] - a[i - 1] == a[i - 1] - a[i - 2]) {
            count++;
            ans += count;
        } else {
            count = 0;
        }
    }

    cout << ans << endl;
    return 0;
}