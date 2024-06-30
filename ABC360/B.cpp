#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin >> s >> t;
    vector<string> v;
    for(int i = 2; i < s.length() / 2 + 1; i++){
        vector<string> temp(i, "");
        for(int k = 0; k < i; k++){
            for(int j = 0; j < s.length() / i + 1; j++){
                temp[k] += s[i * j + k];
            }
        }
        for(auto x : temp){
            v.push_back(x);
        }
    }
    for(auto x : v){
        if(x == t){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}