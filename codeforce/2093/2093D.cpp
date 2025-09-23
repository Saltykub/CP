#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        while (q--) {
            string type;
            cin >> type;
            
            if (type == "->") {
                int x, y;
                cin >> x >> y;
                x--, y--;
                
                long long num = 0;
                for (int i = n - 1; i >= 0; --i) {
                    int cur = 1 << i;
                    if (!(x & cur) && !(y & cur))
                        num ^= 0ll << (2 * i);
                    if ((x & cur) && (y & cur))
                        num ^= 1ll << (2 * i);
                    if ((x & cur) && !(y & cur))
                        num ^= 2ll << (2 * i);
                    if (!(x & cur) && (y & cur))
                        num ^= 3ll << (2 * i);
                }
                cout << num + 1 << '\n';
            }
            else {
                long long num;
                cin >> num;
                num--;
                
                int x = 0, y = 0;
                for (int i = n - 1; i >= 0; --i) {
                    long long cur = 3ll << (2 * i);
                    if ((num & cur) >> (2 * i) == 0)
                        x ^= 0 << i, y ^= 0 << i;
                    if ((num & cur) >> (2 * i) == 1)
                        x ^= 1 << i, y ^= 1 << i;
                    if ((num & cur) >> (2 * i) == 2)
                        x ^= 1 << i, y ^= 0 << i;
                    if ((num & cur) >> (2 * i) == 3)
                        x ^= 0 << i, y ^= 1 << i;
                }
                cout << x + 1 << ' ' << y + 1 << '\n';
            }
        }
    }
    
    return 0;
}