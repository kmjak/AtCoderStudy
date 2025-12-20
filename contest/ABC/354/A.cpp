#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 0;
    int h = 0;
    while(true){
        h += pow(2,i);
        if(h > n){
            cout << i+1 << endl;
            return 0;
        }
        i++;
    }
}