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
    int l1,l2,l3,b1,b2,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if(l1 == l2 && l1 == l3){
        if(b2 + b3 + b1 == l1){
            cout << "Yes\n";
            return;
        }
    }
    if(b1 == b2 && b1 == b3){
        if(l2 + l3 + l1 ==  b1){
            cout << "Yes\n";
            return;
        }
    }
    if(b2 == b3 && l2 + l3 == l1 && b1 + b2 == l1){
        cout << "Yes\n";
        return;
    }
    if(l2 == l3 && b2 + b3 == b1 && l2 + l1 == b1){
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}