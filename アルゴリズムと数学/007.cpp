#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    int c = 0;
    for(int i = 1; i < n + 1; i++){
        if(i % x == 0 || i % y == 0){
            c++;
        }
    }
    cout << c << endl;
}