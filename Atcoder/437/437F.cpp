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
ll seg[4][4*N];
void upd(int idx,int tl, int tr, int pos, int val, int s){
    if(pos < tl || pos > tr) return;
    if(tl == tr) {
        seg[s][idx] = val;
        return;
    }
    int mid = (tl+tr)/2;
    upd(2*idx,tl,mid,pos,val,s);
    upd(2*idx+1,mid+1,tr,pos,val,s);
    seg[s][idx] = max(seg[s][2*idx],seg[s][2*idx+1]);
}
ll get(int idx,int tl, int tr, int l, int r, int s){
    if(l > tr || r < tl) return LLONG_MIN;
    if(tl >= l && tr <= r) return seg[s][idx];
    int mid = (tl+tr)/2;
    return max(get(2*idx,tl,mid,l,r,s),get(2*idx+1,mid+1,tr,l,r,s));
}
void solve (){
    ll n,q;
    cin >> n >> q;
    vector<pii> v(n);
    for(int i = 0; i < 4; i++) for(int j = 0; j < N; j++) seg[i][j] = LLONG_MIN;
    for(auto &[a,b]:v) cin >> a >> b;
    int cnt = 1;
    for(auto [x,y]:v){
        upd(1,1,N,cnt,-x-y,0);
        upd(1,1,N,cnt,-x+y,1);
        upd(1,1,N,cnt,x-y,2);
        upd(1,1,N,cnt,x+y,3);
        cnt++;
    }
    //cout << get(1,1,N,2,2,3) << " ";
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int i,x,y;
            cin >> i >> x >> y;
            upd(1,1,N,i,-x-y,0);
            upd(1,1,N,i,-x+y,1);
            upd(1,1,N,i,x-y,2);
            upd(1,1,N,i,x+y,3);
        }
        else {
            int l,r,x,y;
            cin >> l >> r >> x >> y;
            cout << max({get(1,1,N,l,r,0)+x+y,get(1,1,N,l,r,1)+x-y,get(1,1,N,l,r,2)-x+y,get(1,1,N,l,r,3)-x-y}) << "\n";
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