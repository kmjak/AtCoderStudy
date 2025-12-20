#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,l,r;
    cin >> n >> l >> r;
    for(int i = 1; i < n+1; i++){
        if(i == l){
            for(int j = r; j > l - 1; j--){
                cout << j << " ";
            }
            i = r;
        }else{
                cout << i << " ";
        }
    }
}