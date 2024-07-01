#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin >> n >> s;
    int a[n];
    // vector<int> v;
    // v.push_back(0);
    // for(int i = 0; i < n; i++){
    //     cin >> a[i];
    //     v.push_back(a[i] + v[i]);
    // }
    int c = 0;
    int lm = pow(n,n);
    while(c != lm){
        int pre = 0;
        if(c < n){
            cin >> a[c];
        }
        // int m = v[c / n];
        // if(s < m)break;
        set<int> p;
        int ans = 0;
        int temp = c;
        bool f = true;
        while(temp > n){
            int b = temp % n;
            if(p.count(b))f = false;
            if(f == false)break;
            p.insert(b);
            temp = temp / n;
        }
        p.insert(temp);
        int now = p.size();
        if(pre <= now){
            pre = now;
        }else{
            f = false;
        }
        c++;
        if(f == false){
            continue;
        }
        for(auto x : p){
            if(s < ans)break;
            ans += a[x];
        }
        if(s == ans){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}