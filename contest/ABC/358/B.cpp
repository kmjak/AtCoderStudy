#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin >> n >> t;
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        cin >> h.at(i);
    }
    int time = 0;
    for(auto x : h){
        if(time > x){
            time += t;
        }else{
            time = x + t;
        }
        cout << time << endl;
    }
}