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
const int N = 5e5+10;
bool CASE = false;
ll fw[N];
void add(int i){
    for(; i < N; i+=(i&-i)){
        fw[i]++;
    }
}
ll qs(int i){
    ll ret = 0;
    for(;i > 0; i-= (i&-i)){
        ret += fw[i];
    }
    return ret;
}
void solve (){
    int n;
    cin >> n;
    vll v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    vll idx(n+1);
    for(int i = 1; i <= n; i++){
        idx[v[i]] = i;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int id = idx[i];
        ll left = qs(id-1), right = qs(n)-qs(id);
        add(id);
        ans += (left+1)*(right+1);
    }
    cout << ans;
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}