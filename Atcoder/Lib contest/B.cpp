#include<bits/stdc++.h>
#define ll long long 
#define st first
#define pii pair<ll,ll>
#define nd second
#define pb push_back
using namespace std;
const int N = 5e5+10;
bool CASE = false;
vector<ll> fw(N);

void add(int i,ll val){
    for(;i < N; i+=(i&-i)){
        fw[i]+=val;
    }
}

ll qs(int i){
    ll ret = 0;
    for(;i; i-=(i&-i)){
        ret += fw[i];
    }
    return ret;
}

ll sm(int l, int r){
    return qs(r-1) - qs(l-1);
}

void solve (){
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        add(i,a);
    }
    while(q--){
        ll op,l,r;
        cin >> op >> l >> r;
        if(op){
            cout << sm(++l,++r) << "\n";
        }
        else add(++l,r);
    }
}
int main(){   
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    if(CASE) cin >> t;
    while(t--){   
        solve();
    }
}