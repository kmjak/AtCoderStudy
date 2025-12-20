#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    if(x <= z && y >= z){
        cout << "Yes" << endl;
        return 0;
    }
    if(x >= z && y <= z){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}