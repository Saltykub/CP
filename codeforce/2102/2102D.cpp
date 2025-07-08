#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 2e5+10;
bool CASE = true;
vector<int> fw(N,0);

void add(int i,int val){
    for(;i < N; i+=(i&-i)){
        fw[i]+=val;
    }
}

int qs(int i){
    int ret = 0;
    for(;i;i-=(i&-i)){
        ret += fw[i];
    }
    return ret;
}

int inv (vector<int> v,int n){
    for(int i = 0; i <= n; i++) fw[i] = 0;
    ll ret = 0;
    reverse(v.begin(),v.end());
    for(auto u:v){
        ret+=qs(u);
        add(u,1);
    }

    return ret%2;
}
void solve (){
    int n;
    cin >> n;
    vector<int> e,o;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i%2) o.pb(x);
        else e.pb(x);
    }
    int inv1, inv2;
    inv1 = inv(e,n);
    inv2 = inv(o,n);
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    int ido = 0, ide = 0;
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(i%2) ans.pb(o[ido++]);
        else ans.pb(e[ide++]);
    }
    if(inv1 != inv2) swap(ans[n-1],ans[n-3]);
    for(auto u:ans) cout << u << " ";
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