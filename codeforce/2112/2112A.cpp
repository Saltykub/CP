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
    int a,x,y;
    cin >> a >> x >> y;
    if(x > y) swap(x,y);
    if(x <= a && a <= y) {
        cout << "No\n";
    }
    else cout << "Yes\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}