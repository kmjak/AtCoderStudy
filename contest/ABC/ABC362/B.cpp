#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define rep(s,n) for(int i = s; i < n; i++)
using namespace std;

bool isRightTriangle(int xA, int yA, int xB, int yB, int xC, int yC) {
    int AB2 = (xB - xA) * (xB - xA) + (yB - yA) * (yB - yA);
    int BC2 = (xC - xB) * (xC - xB) + (yC - yB) * (yC - yB);
    int CA2 = (xA - xC) * (xA - xC) + (yA - yC) * (yA - yC);
    return (AB2 + BC2 == CA2) || (AB2 + CA2 == BC2) || (BC2 + CA2 == AB2);
}

int main() {
  vi x(3),y(3);
  rep(0,3){
    cin >> x[i];
    cin >> y[i];
  }

  if (isRightTriangle(x[0], y[0], x[1], y[1], x[2], y[2])) {
      cout << "Yes" << endl;
  } else {
      cout << "No" << endl;
  }

    return 0;
}