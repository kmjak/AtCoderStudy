#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string temp;
    cin >> n;
    string a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        for(int j = 0; j < n; j++){
        if(temp[j] != a[i][j]){
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
}