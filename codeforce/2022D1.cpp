#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n;
    cin >> n;
    int i = 1;
    while(n-i > 1){
        int a,b;
        cout << "? " << i << " " << n << endl;
        cin >> a;
        cout << "? " << n << " " << i << endl;
        cin >> b;
        if(a == b) {
            n--;
            i++;
        }
        else {
            int x,y;
            cout << "? " << i << " " << n-1 << endl;
            cin >> x;
            cout << "? " << n-1 << " " << i << endl;
            cin >> y;
            if(x == y) {
                cout << "! " << n << endl;
                return;
            }
            else {
                cout << "! " << i << endl;
                return;
            }
        }
    }
    if(n == i){
        cout << "! " << i << endl;
    }
    else {
        int x,y;
        cout << "? " << i << " " << i-1 << endl;
        cin >> x;
        cout << "? " << i-1 << " " << i << endl;
        cin >> y;
        if(x == y) cout << "! " << n << endl;
        else cout << "! " << i << endl;
    }
    return;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}