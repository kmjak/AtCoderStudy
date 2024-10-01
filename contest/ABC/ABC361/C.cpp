#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    vi a(n);
    rep(0,n) cin >> a[i];
    int ans = 1000000000;
    vector<int> pattern(n-k);
    int j = 0;
    for(int i = n-k-1; i > -1; i--){
        pattern[j] = i;
        j++;
    }
    while(pattern[n-k-1] != n - (n - k)){ 
        int min = 1000000000;
        int max = 0;
        for(int i = n-k-1; i > -1; i--){
            if(a[pattern[i]] < min)min = a[pattern[i]];
            if(a[pattern[i]] > max)max = a[pattern[i]];
        }
        if(ans > max - min)ans = max - min;
        pattern[0]++;
        bool flag = true;
        while(flag){
            flag = false;
            for(int i = 0; i < n-k; i++){
                if(pattern[i] >= n){
                    pattern[i+1]++;
                    pattern[i] = pattern[i+1] + 1;
                    flag = true;
                }
            }
            if(pattern[n-k-1] == n - (n - k))break;
        }
    }
    cout << ans << endl;
}