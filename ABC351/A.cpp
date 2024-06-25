#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans = 1;
    int temp;
    for(int i = 0; i < 9; i++){
        cin >> temp;
        ans += temp;
    }
    for(int i = 0; i < 8; i++){
        cin >> temp;
        ans -= temp;
    }
    cout << ans << endl;
}