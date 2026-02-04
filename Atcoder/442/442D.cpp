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
bool CASE = false;
ll fw[N];
void add(int i, int val){
    for(;i < N; i+=(i&-i)) fw[i]+=val;
}
ll qs(int i){
    ll ret = 0;
    for(;i; i-=(i&-i)) ret += fw[i];
    return ret;
}
void solve (){
    int n,q;
    cin >> n >> q;
    vll v(n+1);
    for(int i = 1;i <= n; i++){
        int x;
        cin >> x;
        add(i,x);
        v[i] = x;
    }
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
            add(x,v[x+1]-v[x]);
            add(x+1,v[x]-v[x+1]);
            swap(v[x],v[x+1]);
        }
        else {
            int l,r;
            cin >> l >> r;
            if(l == 1){
                cout << qs(r) << "\n";
            }
            else {
                cout << qs(r)-qs(l-1) << "\n";
            }
        }
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