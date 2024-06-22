#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin >> s >> t;
    int j = 0;
    for(int i = 0; i < t.length(); i++){
        if(j == s.length()){
            break;
        }
        if(s.at(j) == t.at(i)){
            j++;
            cout << i+1 << " ";
        }
    }
}