#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = false;
void solve (){
    ll sm = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        if(i%2 == 0) sm += x;
    }
    cout << sm;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}