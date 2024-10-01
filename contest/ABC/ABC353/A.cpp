#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++){
        cin >> b.at(i);
    }
    for(int i = 0; i < n; i++){
        if(b.at(i) > b.at(0)){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}