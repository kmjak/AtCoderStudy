#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int total = 0;
    vector<string> h(n);
    for(int i = 0; i < n; i++){
        cin >> h.at(i);
        int t;
        cin >> t;
        total += t;
    }
    sort(h.begin(),h.end());
    cout << h.at(total % n) << endl;
}