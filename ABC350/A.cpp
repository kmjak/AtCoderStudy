#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    if(s == "ABC000" || s == "ABC316" || s > "ABC349"){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}