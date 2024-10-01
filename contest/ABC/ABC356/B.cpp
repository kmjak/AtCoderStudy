#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m,0);
    for(int i = 0; i < m; i++){
        cin >> a.at(i);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int t = 0;
            cin >> t;
            b.at(j) += t;
        }
    }
    for(int i = 0; i < m; i++){
        if(a.at(i) > b.at(i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}