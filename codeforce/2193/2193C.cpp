#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vll vector<ll>
using namespace std;
const int N = 2e5+10;
bool CASE = true;
void solve (){
    int n,q;
    cin >> n >> q;
    vll a(n),b(n);
    for(auto &u:a) cin >> u;
    for(auto &u:b) cin >> u;
    a[n-1] = max(a[n-1],b[n-1]);
    for(int i = n-2; i >= 0; i--){
        a[i] = max({b[i],a[i+1],a[i]});
    }
    for(int i = 1; i < n; i++) a[i] += a[i-1];
    while(q--){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        if(l == 0){
            cout << a[r] << " ";
        }
        else {
            cout << a[r]-a[l-1] << " ";
        }
    }
    cout << "\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}