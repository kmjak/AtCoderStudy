#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < m; i++){
        cin >> b.at(i);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0;
    int64_t total = 0;
    int j = 0;
    while(i < n && j < m){
        if(b.at(j) <= a.at(i)){
            total += a.at(i);
            j++;
        }
        i++;
    }
    if(m == j){
        cout << total << endl;
    }else{
        cout << -1 << endl;
    }
}