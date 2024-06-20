#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> g(n);
    for(int i = 0; i < n; i++){
        cin >> g.at(i);
    }
    int c = 0;
    while(count(g.begin(),g.end(),0) != n){
        int total = 0;
        for(int i = 0; i < n; i++){
            if(g.at(i) + total <= k){
                total += g.at(i);
                g.at(i) = 0;
            }else{
                break;
            }
        }
        c++;
    }
    cout << c << endl;
}