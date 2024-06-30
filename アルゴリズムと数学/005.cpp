#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ans += temp;
    }
    cout << ans % 100 << endl;
}