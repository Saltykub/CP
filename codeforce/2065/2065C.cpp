#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
int t = 0;
void solve (){
    t++;
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n),b(m);
    for(auto &x:a) cin >> x;
    for(auto &x:b) cin >> x;
    sort(b.begin(),b.end());
    if(b[0] - a[0] < a[0]) a[0] = b[0]-a[0];
    for(int i = 1; i < n; i++){
        int l = 0, r = m-1;
        while(l < r){
            int mid = (l+r)/2;
            if(b[mid]-a[i] >= a[i-1]) r = mid;
            else l = mid+1;
           
        }
        if(b[l] - a[i] >= a[i-1]){
            if(a[i] >= a[i-1]) a[i] = min(a[i],b[l]-a[i]);
            else a[i] = b[l]-a[i];
        }
    }
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}