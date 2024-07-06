#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    
    int x = min(d, j) - max(a, g);
    int y = min(e, k) - max(b, h);
    int z = min(f, l) - max(c, i);
    
    int total = max(0, x) * max(0, y) * max(0, z);
    
    if (total > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
