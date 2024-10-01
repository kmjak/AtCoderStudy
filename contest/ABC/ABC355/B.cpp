#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n), b(m),c(n+m);
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
        c.at(i) = a.at(i);
    }
    for(int i = 0; i < m; i++){
        cin >> b.at(i);
        c.push_back(b.at(i));
    }
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    int flag = 0;
    for(auto x : c){
        if(count(a.begin(),a.end(),x)){
            flag++;
        }else{
            flag = 0;
        }
        if(flag == 2){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

}