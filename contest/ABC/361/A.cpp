#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
    int n,k,x;
    cin >> n >> k >> x;
    vi a(n);
    rep(0,n) cin >> a[i];
    rep(0,n){
        if(i == k){
            cout << x << " ";
        }
        cout << a[i] << " ";
    }
    if(k > n-1) cout << x;
    cout << endl;
    return 0;
}